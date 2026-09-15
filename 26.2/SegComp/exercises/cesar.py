message = input("type message: ")
k = int(input("type key: "))
alpha_only = True if input("alpha only? [Y/N] ") == 'Y' else False

discrp = list()

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

        discrp.append(chr(new_ascii))
    else:
        discrp.append(message[i])


print("discrypted message: ", ''.join(discrp))
