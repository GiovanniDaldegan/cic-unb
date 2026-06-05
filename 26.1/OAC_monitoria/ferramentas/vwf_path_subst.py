import os

def replace_in_file(file_path:str, target_start:str, target_end:str, new_dir:str, new_file_name:str=None):
    """
    Dado um arquivo, substitui todas as ocorrências de uma certa string
    """
    
    if not os.path.isfile(file_path):
        print("Arquivo não existe.")
        return
    
    old_string, old_path = "", ""
    found = False

    try:
        with open(file_path, "r") as f:
            for line in f.readlines()[:6]:
                start_vwf = line.find(target_start)
                end_vwf = start_vwf + line[start_vwf:].find(target_end)

                if start_vwf > 0 and end_vwf > start_vwf:
                    old_path = line[start_vwf:end_vwf+len(target_end)]
                    found = True
                    old_string = os.path.dirname(old_path)
                    print("substituir:", old_string)
                    break

            if not found:
                print("String alvo não presente.")
                return

        try:
            with open(file_path, "r+") as f:
                # substituir o diretório do projeto
                content = f.read()
                content = content.replace(old_string, new_dir.replace("\\", "/"))

                # apagar referências a simulações
                if new_file_name != "":
                    old_name = os.path.basename(old_path)[:-4]
                    print("nome antigo:", old_name)
                    content = content.replace(old_name, new_name)
                
                # apagar -novopt
                content = content.replace(" -novopt", "")

                # reescrever arquivo
                f.seek(0)
                f.write(content)
                f.truncate()

                return True

        except Exception as e:
            print("Erro na escrita.", e)

    except Exception as e:
        print("Erro na leitura.", e)


if __name__ == "__main__":
    file_path = input("Caminho do arquivo: ")
    new_name = input("Novo nome [sem .vwf, vazio para manter o nome atual]: ")

    if file_path[-4:] == ".vwf":
        try:
            if not replace_in_file(file_path, "C:/", ".vwf", os.path.dirname(file_path), new_name):
                exit()

            if new_name != "" and os.path.isfile(file_path):
                new_path = os.path.normpath(os.path.join(os.path.dirname(file_path), new_name + ".vwf"))
                print("Novo arquivo:", new_path)

                os.rename(file_path, new_path)
        except Exception as e:
            print