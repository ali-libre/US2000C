input_file = "pwr"
output_file = "ascii_output.txt"

with open(input_file, "r") as f:
    hex_data = f.read().strip()


hex_bytes = hex_data.split()

ascii_text = ''.join([chr(int(b, 16)) for b in hex_bytes])

with open(output_file, "w", encoding="utf-8") as f:
    f.write(ascii_text)

print("converted...")
