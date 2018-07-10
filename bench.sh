#!/bin/sh

PYTHON=python3

${PYTHON} -c 'from sys import version; print(version)'
${PYTHON} -c 'from callbench import have_ccall; print(f"PEP 580: {have_ccall(len)}")'


timeit()
{
    ${PYTHON} -m perf timeit --quiet --duplicate 200 -s 'from callbench import call, fastcall, obj, meth, fastmeth, umeth, ufastmeth' "$@"
}


for args in "" "1, 2, 3" "1, two=2"; do
    echo

    echo -n "VARARGS function($args):             "
    timeit "call($args)"

    echo -n "FASTCALL function($args):            "
    timeit "fastcall($args)"

    echo -n "VARARGS obj.method($args):           "
    timeit "obj.meth($args)"

    echo -n "FASTCALL obj.method($args):          "
    timeit "obj.fastmeth($args)"

    echo -n "VARARGS bound method($args):         "
    timeit "meth($args)"

    echo -n "FASTCALL bound method($args):        "
    timeit "fastmeth($args)"

    echo -n "VARARGS unbound method(obj, $args):  "
    timeit "umeth(obj, $args)"

    echo -n "FASTCALL unbound method(obj, $args): "
    timeit "ufastmeth(obj, $args)"

    echo -n "tp_call($args):                      "
    timeit "obj($args)"
done
