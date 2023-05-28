import unittest as ut
import os

# pytest tests/


class MyTest(ut.TestCase):
    def test_cpp(self):
        fnames = sorted(fname for fname in os.listdir("answer"))
        for fname in fnames:
            print(f"<<< {fname}")
            fname_no_ext = fname.rsplit('.', 1)[0]
            command = f"/usr/bin/g++-11 -fdiagnostics-color=always -g ./answer/{fname}  -o ./bin/{fname_no_ext} -I ./src"
            os.system(command)
            os.system(f"./bin/{fname_no_ext}")


if __name__ == "__main__":
    ut.main()
