from callbench.callables import *

obj = Callable()

meth = obj.meth
umeth = Callable.meth

try:
    fastmeth = obj.fastmeth
    ufastmeth = Callable.fastmeth
except AttributeError:
    pass


def have_PEP_580(obj):
    return bool(type(obj).__flags__ & 2048)


def have_PEP_590(obj):
    return bool(type(obj).__flags__ & 2)
