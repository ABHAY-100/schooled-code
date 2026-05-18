import os

source = input("source : ")
destination = input("destination : ")

src_fd = os.open(source, os.O_RDONLY)

dest_fd = os.open(
    destination,
    os.O_WRONLY | os.O_CREAT | os.O_TRUNC
)

while True:
    data = os.read(src_fd, 1024)

    if not data:
        break

    os.write(dest_fd, data)

os.close(src_fd)
os.close(dest_fd)

print("File copied successfully.")
