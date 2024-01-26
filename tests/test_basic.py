from __future__ import annotations

import scikit_build_example as m

def test_hello():
    print(m.__file__)
    assert(m.__file__ == None)
    m.hello()

