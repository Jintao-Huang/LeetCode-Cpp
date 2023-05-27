import unittest as ut
import os

# pytest tests/


class MyTest(ut.TestCase):
    def test_cpp(self):
        folder = "./bin"
        fnames = sorted(fname for fname in os.listdir(folder) if len(fname) == 4)
        for fname in fnames:
            path = os.path.join(folder, fname)
            print(f"<<< {path}")
            os.system(path)


if __name__ == "__main__":
    ut.main()
