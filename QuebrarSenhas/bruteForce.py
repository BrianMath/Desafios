from zipfile import ZipFile


def QuebraSenhaFacil(zip_file):
    with ZipFile(zip_file) as zf:
        # posição 0
        for a in range(0, 10):
            # posição 1
            for b in range(0, 10):
                # posição 2
                for c in range(0, 10):
                    # posição 3
                    for d in range(0, 10):
                        senha = f"{a}{b}{c}{d}"

                        try:
                            zf.extractall(pwd=bytes(senha, "utf-8"))
                        except:
                            pass
                        else:
                            return senha


# Programa
try:
    print(f"Senha do arquivo: {QuebraSenhaFacil('senhaFacil.zip')}")
except:
    print("\033[31mArquivo inválido: forneça um arquivo .zip válido e tente novamente\033[m")
