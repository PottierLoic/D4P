import json
import requests
import os

def contains_localized(value):
  if isinstance(value, str):
    return "localized" in value.lower()
  return False

def remove_localized_entries(data):
  if isinstance(data, dict):
    keys_to_remove = [key for key in data if contains_localized(key) or contains_localized(data[key])]
    for key in keys_to_remove:
      del data[key]
    for key in data:
      data[key] = remove_localized_entries(data[key])
  elif isinstance(data, list):
    data = [item for item in data if not contains_localized(item)]
    data = [remove_localized_entries(item) for item in data]
  return data

def download_json(url, local_file):
  response = requests.get(url)
  response.raise_for_status()
  with open(local_file, 'w', encoding='utf-8') as f:
    json.dump(response.json(), f, indent=4)


def main():
  url = 'https://raw.githubusercontent.com/Lothrik/diablo4-build-calc/master/database/build-52025.json'
  dl_file = 'data/downloaded.json'
  output_file = 'data/raw_data.json'
  download_json(url, dl_file)
  with open(dl_file, 'r', encoding='utf-8') as f:
    data = json.load(f)
  data = remove_localized_entries(data)
  with open(output_file, 'w', encoding='utf-8') as f:
    json.dump(data, f, indent=4)
  os.remove(dl_file)
  print("Processing completed. Updated JSON written to data/raw_data.json")
if __name__ == "__main__":
  main()
