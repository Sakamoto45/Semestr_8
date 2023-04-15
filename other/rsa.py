from Crypto.Util.number import long_to_bytes, inverse, bytes_to_long, getPrime
from typing import Tuple
import sys
ct = 128822112131390197213908544756255577831512177820570331241520407471167354387529284539408796758976445068243200219189129601204903199265834585067022145284056019082849848692381909789599301236599673789802908176324366474065891286445175726455206279370411859879367089752450805784966433902895901543788132447608102826593
e = 65535
n = 160010028020903269593997360264940371254968384818252182340619431967394546380585044260196418262558621591709193616822357112706431368205301054852764427225339354023196236616133870748975939928359121900542912972323556270981568270460676185900713057864809139762912335537590806544124038933262893904046854345040651513969


# long type, 32bit OS 4B, 64bit OS 8B (1bit for sign)
sys.setrecursionlimit(1000000)

# flag = "***REDACD***"

# pt = bytes_to_long(flag.encode())

# n = getPrime(1200)
# e = 65535

# ct = pow(pt, e, n)
# print(ct)
# print(e)
# print(n)


# print(pt)


def egcd(a: int, b: int) -> Tuple[int, int, int]:
    """return (g, x, y) such that a*x + b*y = g = gcd(a, b)"""
    if a == 0:
        return (b, 0, 1)
    else:
        b_div_a, b_mod_a = divmod(b, a)
        g, x, y = egcd(b_mod_a, a)
        return (g, y - b_div_a * x, x)


def modinv(a: int, b: int) -> int:
    """return x such that (x * a) % b == 1"""
    g, x, _ = egcd(a, b)
    if g != 1:
        raise Exception('gcd(a, b) != 1')
    return x % b


d = modinv(e, n-1)

print(long_to_bytes(pow(ct, d, n)))


# m ^ private ^ public = m

# private * public = 1 mod n
# public = private ^ n-2


# print(ct)
# print(e)
# print(n)
