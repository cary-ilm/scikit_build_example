from __future__ import annotations

import scikit_build_example as m

def test_version():
    assert m.__version__ == "0.1.3"


def test_hello():
    m.hello()

