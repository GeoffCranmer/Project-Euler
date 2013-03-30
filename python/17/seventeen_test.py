import seventeen
import unittest

class TestNumLetters(unittest.TestCase):

    def runTest(self):
        self.assertEqual(seventeen.numletters(1), 3)
        self.assertEqual(seventeen.numletters(53), 10)
        self.assertEqual(seventeen.numletters(300), 12)
        self.assertEqual(seventeen.numletters(736), 24)

class TestSumNumLetters(unittest.TestCase):

    def runTest(self):
        self.assertEqual(seventeen.sumnumletters(1, 1000), 21124)

if __name__ == '__main__':
    suitenumletters = unittest.TestLoader().loadTestsFromTestCase(TestNumLetters)
    suitesumnumletters = unittest.TestLoader().loadTestsFromTestCase(TestSumNumLetters)
    suiteall = unittest.TestSuite([suitenumletters, suitesumnumletters])
    unittest.TextTestRunner(verbosity=2).run(suiteall)
