from __future__ import annotations

import Hello as m

def test_hello():
    print(f"m: {m}")
    print(f"dir(m): {dir(m)}")
    print(f"m.__name__={m.__name__}")
    print(f"m.__file__={m.__file__}")
    m.hello()

