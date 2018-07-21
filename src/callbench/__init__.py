from callbench.callables import *

obj = Callable()

meth = obj.meth
umeth = Callable.meth

try:
    fastmeth = obj.fastmeth
    ufastmeth = Callable.fastmeth
except AttributeError:
    pass
