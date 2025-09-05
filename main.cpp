import random
import os

# تعريف القيم الثابتة
class enTestLevel:
    Easy = 1
    Med = 2
    Hard = 3
    LevelMix = 4

class enQuestionLevel:
    EasyQ = 1
    MedQ = 2
    HardQ = 3
    MixQ = 4

class enTestType:
    Add = 1
    Sub = 2
    Mul = 3
    Div = 4
    OpMix = 5

class enQuestionType:
    QAdd = 1
    QSub = 2
    QMul = 3
    QDiv = 4
    QOpMix = 5

class enTestFinalResult:
    PASS = 1
    FAIL = 2

# تعريف الهياكل
class stTestInformations:
    def __init__(self):
        self.QueistoinsNumber = 0
        self.ExamLevel = None
        self.Type = None
        self.RightAnswersNumber = 0
        self.WrongAnsersNumber = 0
        self.PassOrFail = None

class stQuestionsInformation:
    def __init__(self):
        self.QuestionForm = ""
        self.Answer = 0
        self.Type = None
        self.Level = None

# الوظائف المساعدة
def RandomNumber(From, To):
    return random.randint(From, To)

def ReadNumberInRange(From, To, Messege):
    while True:
        try:
            Number = int(input(Messege))
            if From <= Number <= To:
                return Number
        except:
            continue

def ReadPositiveNumber(Messege):
    while True:
        try:
            Number = int(input(Messege))
            if Number >= 0:
                return Number
        except:
            continue

def TestLevel():
    return ReadNumberInRange(1, 4, "اختر مستوى الاختبار [1] سهل , [2] متوسط , [3] صعب , [4] مختلط؟ ")

def QuestionsType():
    return ReadNumberInRange(1, 5, "اختر نوع العملية [1] جمع , [2] طرح , [3] ضرب , [4] قسمة , [5] مختلط؟ ")

def Questionlevel(TestLevel):
    if TestLevel == enTestLevel.Easy:
        return enQuestionLevel.EasyQ
    elif TestLevel == enTestLevel.Med:
        return enQuestionLevel.MedQ
    elif TestLevel == enTestLevel.Hard:
        return enQuestionLevel.HardQ
    else:
        return RandomNumber(1, 3)

def QuestionType(TestType):
    if TestType == enTestType.Add:
        return enQuestionType.QAdd
    elif TestType == enTestType.Sub:
        return enQuestionType.QSub
    elif TestType == enTestType.Mul:
        return enQuestionType.QMul
    elif TestType == enTestType.Div:
        return enQuestionType.QDiv
    else:
        return RandomNumber(1, 4)

# توليد الأسئلة حسب المستوى
def GenerateQuestion(Question):
    if Question.Level == enQuestionLevel.EasyQ:
        First = RandomNumber(1, 10)
        Second = RandomNumber(1, 10)
    elif Question.Level == enQuestionLevel.MedQ:
        First = RandomNumber(10, 50)
        Second = RandomNumber(1, 10)
    else:
        First = RandomNumber(10, 100)
        Second = RandomNumber(10, 100)

    Question.QuestionForm = f"\n{First}\n{Second}"
    if Question.Type == enQuestionType.QAdd:
        Question.QuestionForm += " +\n___________________\n"
        Question.Answer = First + Second
    elif Question.Type == enQuestionType.QSub:
        Question.QuestionForm += " -\n___________________\n"
        Question.Answer = First - Second
    elif Question.Type == enQuestionType.QMul:
        Question.QuestionForm += " *\n___________________\n"
        Question.Answer = First * Second
    elif Question.Type == enQuestionType.QDiv:
        Question.QuestionForm += " /\n___________________\n"
        Question.Answer = First // Second if Second != 0 else 0

def FillQuestionInformation(QuestionInfo, TestInfo):
    QuestionInfo.Level = Questionlevel(TestInfo.ExamLevel)
    QuestionInfo.Type = QuestionType(TestInfo.Type)
    GenerateQuestion(QuestionInfo)

def FillAllQuestionsInfo(Questions, TestInfo):
    for i in range(TestInfo.QueistoinsNumber):
        FillQuestionInformation(Questions[i], TestInfo)

def ChangeScreenColor(PassOrFail):
    if PassOrFail == enTestFinalResult.PASS:
        os.system("color 2F")
    else:
        print('\a')
        os.system("color 4F")

def AnswerDecied(UserNumber, RightAnswer, TestInfo):
    if UserNumber == RightAnswer:
        print("إجابة صحيحة :-) \n")
        ChangeScreenColor(enTestFinalResult.PASS)
        TestInfo.RightAnswersNumber += 1
    else:
        print("إجابة خاطئة :-( \a\n")
        ChangeScreenColor(enTestFinalResult.FAIL)
        print(f"الإجابة الصحيحة هي : {RightAnswer}")
        TestInfo.WrongAnsersNumber += 1

def PassOrFail(TestInfo):
    return enTestFinalResult.PASS if TestInfo.RightAnswersNumber > TestInfo.WrongAnsersNumber else enTestFinalResult.FAIL

def PASSOrFAILScreen(IsPass):
    print("\n________________________________________\n")
    if IsPass == enTestFinalResult.PASS:
        print("        النتيجة النهائية: ناجح :-)        ")
    else:
        print("        النتيجة النهائية: راسب :-(        \a")
    print("________________________________________\n")
    ChangeScreenColor(IsPass)

def TestTypeAsString(TestType):
    return ["جمع", "طرح", "ضرب", "قسمة", "مختلط"][TestType - 1]

def TestLevelAsString(TestLevel):
    return ["سهل", "متوسط", "صعب", "مختلط"][TestLevel - 1]

def FinalResultScreen(TestInfo):
    print("\n")
    print(f"عدد الأسئلة : {TestInfo.QueistoinsNumber}")
    print(f"مستوى الأسئلة : {TestLevelAsString(TestInfo.ExamLevel)}")
    print(f"نوع العملية : {TestTypeAsString(TestInfo.Type)}")
    print(f"عدد الإجابات الصحيحة : {TestInfo.RightAnswersNumber}")
    print(f"عدد الإجابات الخاطئة : {TestInfo.WrongAnsersNumber}")
    print("\n________________________________________\n")

def ScreenReset():
    os.system("cls")
    os.system("color 0f")

# البرنامج الرئيسي
def main():
    random.seed()
    TestInfo = stTestInformations()

    while True:
        TestInfo.RightAnswersNumber = 0
        TestInfo.WrongAnsersNumber = 0

        ScreenReset()

        TestInfo.QueistoinsNumber = ReadPositiveNumber("كم عدد الأسئلة التي تريد الإجابة عليها؟ ")
        TestInfo.ExamLevel = TestLevel()
        TestInfo.Type = QuestionsType()

        Questions = [stQuestionsInformation() for _ in range(TestInfo.QueistoinsNumber)]
        FillAllQuestionsInfo(Questions, TestInfo)

        for TestRound in range(1, TestInfo.QueistoinsNumber + 1):
            print(f"\nالسؤال [{TestRound} / {TestInfo.QueistoinsNumber}]")
            print(Questions[TestRound - 1].QuestionForm)
            try:
                UserAnswer = int(input())
            except:
                UserAnswer = 0
            AnswerDecied(UserAnswer, Questions[TestRound - 1].Answer, TestInfo)

        TestInfo.PassOrFail = PassOrFail(TestInfo)
        PASSOrFAILScreen(TestInfo.PassOrFail)
        FinalResultScreen(TestInfo)

        while True:
            WantPlayAgain = input("\nهل تريد اللعب مرة أخرى؟ Y / N ").lower()
            if WantPlayAgain in ['y', 'n']:
                break

        if WantPlayAgain == 'n':
            break

if __name__ == "__main__":
    main()
