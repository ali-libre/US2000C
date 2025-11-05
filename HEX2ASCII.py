input_file = "pwr"
output_file = "ascii_output.txt"

with open(input_file, "r") as f:
    hex_data = f.read().strip()

# حذف فاصله‌ها و جدا کردن هگزها
hex_bytes = hex_data.split()

# تبدیل هر بایت هگز به کاراکتر ASCII
ascii_text = ''.join([chr(int(b, 16)) for b in hex_bytes])

# نوشتن در فایل خروجی
with open(output_file, "w", encoding="utf-8") as f:
    f.write(ascii_text)

print("✅ تبدیل انجام شد! نتیجه در فایل ascii_output.txt ذخیره شد.")
