
Description
===========

Given two sets of points, finds all pairwise indices such that the
separation between any pair satisfies ``separation >=0 RMIN && separation < RMAX``.

Installation
============

Pre-requisites
--------------

1. ``make >= 3.80``
2. OpenMP capable compiler like ``icc``, ``gcc`` or ``clang >= 3.7``. If
   not available, please disable ``USE_OMP`` option option in
   ``theory.options`` and ``mocks.options``. You might need to ask your
   sys-admin for system-wide installs of the compiler; if you prefer to
   install your own then ``conda install gcc`` (MAC/linux) or
   ``(sudo) port install gcc5`` (on MAC) should work. *Note ``gcc`` on
   macports defaults to ``gcc48`` and the portfile is currently broken
   on ``El Capitan``*.
3. ``python >= 2.6`` or ``python>=3.4`` for compiling the C extensions.
4. ``numpy>=1.7`` for compiling the C extensions.

*If python and/or numpy are not available, then the C extensions will
not be compiled*.

*Default compiler on MAC is set to ``clang``, if you want to specify a
different compiler, you will have to call ``make CC=yourcompiler``*

Preferred Method
----------------

::

    $ git clone https://github.com/manodeep/pairwise_indices/
    $ make 
    $ make install
    $ python setup.py install (--user)



Author
======

pairwise_indices is written/maintained by Manodeep Sinha. Please contact the
`author <mailto:manodeep@gmail.com>`__ in case of any issues.


LICENSE
=======

pairwise_indices is released under the MIT license. Basically, do what you want
with the code including using it in commercial application.

Project URL
===========

-  website (https://manodeep.github.io/pairwise_indices/)
-  version control (https://github.com/manodeep/pairwise_indices/)

