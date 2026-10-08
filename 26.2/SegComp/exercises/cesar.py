encr_decrp = int(input("encrypt (0), decrypt (1): "))

if not encr_decrp:
    message = input("type message: ")
else:
    message = input("type chipher: ")

k = int(input("type key: ")) * (-1 if encr_decrp else 1)
alpha_only = True if input("alpha only? [Y/N]: ").lower() == 'y' else False

decrp = list()

print(message)

for i in range(len(message)):
    ascii_code = ord(message[i])

    if (alpha_only and message[i].isalpha()) or (not alpha_only):
        new_ascii = ord(message[i]) + k
        print(f"{ord(message[i])} -> {new_ascii}", end=" | ")

        print(f"{new_ascii} -> ", end="")

        if (ord('A') <= ascii_code and ascii_code <= ord('Z')) and new_ascii > ord('Z'):
            new_ascii = ord('A') + (new_ascii - ord('Z')-1)

        print(new_ascii)

        decrp.append(chr(new_ascii))
    else:
        decrp.append(message[i])


print("decrypted message: ", ''.join(decrp))
