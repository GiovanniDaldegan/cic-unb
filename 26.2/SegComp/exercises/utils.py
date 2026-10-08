
def mdc(a, b):
    while b:
        a, b = b, a % b
    return a

"""
for i in range(71):
    print(i, end=" ")
    print("SIM", end=" ") if pow(7, i, 71) == 3 else print("não", end=" ")
    print(pow(7, i, 71))
"""

class EC:
    def __init__(self, q, a, b):
        self.q = q
        self.a = a
        self.b = b

# soma de pontos em uma curva elíptica
add_mult = bool(input("add (0), mult (1): ") != "0")
q = int(input("prime: "))
[a, b] = [int(i) for i in input("a,b: ").split(",")]
curve = EC(q, a, b)
print(f"curva: E{curve.q}({curve.a},{curve.b})")

if not add_mult:
    point1 = [int(i) for i in input("point 1 x,y: ").split(",")]
    point2 = [int(i) for i in input("point 2 x,y: ").split(",")]
    coef = 0

    point3 = [333, 333]

    if point1 == point2:
        coef = (3 * pow(point1[0], 2) + curve.a) / (2 * point1[1]) % curve.q
        print("iguais", coef)
    else:
        coef = (point2[1] - point1[1]) / (point2[0] - point1[0])
        print("diff", coef)

    point3[0] = int(pow(coef, 2) - point1[0] - point2[0]) % curve.q
    point3[1] = int(coef * (point1[0] - point3[0]) - point1[1]) % curve.q

    print(f"{point1} + {point2} = {point3}")

else:
    point2 = input("point x,y: ").split(",")
    n = int(input(")\nscalar: "))
    q = int(input("prime: "))
