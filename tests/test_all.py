import unittest as ut
import os

# python tests/test_all.py


class MyTest(ut.TestCase):
    def test_answer(self):
        print("<<< test_answer")
        fnames = sorted(fname for fname in os.listdir("./answer"))
        for fname in fnames:
            print(f"<<< {fname}")
            fname_no_ext = fname.rsplit('.', 1)[0]
            command = f"/usr/bin/g++-11 -fdiagnostics-color=always -g ./answer/{fname}  -o ./bin/{fname_no_ext} -I ./src"
            os.system(command)
            os.system(f"./bin/{fname_no_ext}")

    def test_test(self):
        print("<<< test_test")
        for cur_dir, _, fname_list in os.walk("./tests"):
            for fname in fname_list:
                fname_no_ext, ext_name = fname.rsplit('.', 1)
                if ext_name != "cpp":
                    continue
                print(f"<<< {fname}")
                src_path = os.path.join(cur_dir, fname)
                command = f"/usr/bin/g++-11 -fdiagnostics-color=always -g {src_path}  -o ./bin/{fname_no_ext} -I ./src"
                os.system(command)
                os.system(f"./bin/{fname_no_ext}")
if __name__ == "__main__":
    ut.main()
