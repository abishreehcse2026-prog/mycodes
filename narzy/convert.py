

from scipy.io import arff
import pandas as pd
from pathlib import Path

file_path = input("Paste the full path of your ARFF file: ").strip()
file_path = file_path.strip("'\"")

data, metadata = arff.loadarff(file_path)
df = pd.DataFrame(data)

for column in df.select_dtypes(["object"]).columns:
    df[column] = df[column].apply(
        lambda value: value.decode("utf-8")
        if isinstance(value, bytes) else value
    )

output_path = str(Path(file_path).with_suffix(".csv"))
df.to_csv(output_path, index=False)

print("Conversion successful!")
print("CSV saved at:", output_path)
