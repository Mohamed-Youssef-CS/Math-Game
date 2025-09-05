
#include <iostream> #include <cstdlib> #include <string>
using namespace std;
enum enTestLevel { Easy = 1, Med = 2, Hard = 3, LevelMix = 4 };
enum enQuestionLevel { EasyQ = 1, MedQ = 2, HardQ = 3 , MixQ = 4};
enum enTestType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };
enum enQuestionType { QAdd = 1, QSub = 2, QMul = 3, QDiv = 4, QOpMix = 5 };
enum enTestFinalResult { PASS = 1 , FAIL = 2 };
struct stTestInformations { short QueistoinsNumber = 0; enTestLevel ExamLevel; enTestType Type; short RightAnswersNumber = 0; short WrongAnsersNumber = 0; enTestFinalResult PassOrFail; };
struct stQuestionsInformation { string QuestionForm = ""; int Answer; enQuestionType Type; enQuestionLevel Level; };
int RandomNumber(int From, int To) { int RandNumber = rand() % (To - From + 1) + From;
return RandNumber;




}
int ReadNumberInRange(int From, int To, string Messege) { int Number; do { cout << Messege; cin >> Number; } while (Number < From || Number > To); return Number; }
int ReadPositiveNumber(string Messege) { int Number = 0; do { cout << Messege; cin >> Number;
} while (Number < 0);

return Number;


}
enTestLevel TestLevel() { short TLevel = ReadNumberInRange(1, 4, "Enter Test level [1] Easy , [2] Med , [3] Hard , [4] Mix ? " );
return (enTestLevel)TLevel;




}
enTestType QuestionsType() { short QType = ReadNumberInRange(1, 5, "Enter Operation Type [1] Add , [2] Sub , [3] Mul; , [4] Div , [5] Mix ? ");
return (enTestType)QType;




}
enQuestionLevel Questionlevel(enTestLevel TestLevel) { switch (TestLevel) { case Easy: return EasyQ; case Med: return MedQ; case Hard: return HardQ; default: // if Mix Will return Random Level : Easy - Mid - Hard return (enQuestionLevel)RandomNumber(1 , 3); } }
enQuestionType QuestionType(enTestType TestType) {
switch (TestType)
{
case Add:
	return QAdd;
case Sub:
	return QSub;
case Mul:
	return QMul;
case Div:
	return QDiv;
default:
	// if Mix Will return Random Level : Easy - Mid - Hard
	return (enQuestionType)RandomNumber(1, 4);
}



}
void EasyQustion(stQuestionsInformation &Question) { //Fill Easy Questions
short FirstQNumber  = RandomNumber(1, 10) , SecondQNumber = RandomNumber(1, 10);

string GeneralForm = "\n" + to_string(FirstQNumber) + "\n" + to_string(SecondQNumber) ;

switch (Question.Type)
{
case Add:
	Question.QuestionForm = GeneralForm + " +\n" + "___________________\n";

	Question.Answer = FirstQNumber + SecondQNumber;
	break;

case Sub:
	Question.QuestionForm = GeneralForm + " -\n" + "___________________\n";

	Question.Answer = FirstQNumber - SecondQNumber;
	break;

case Mul:
	Question.QuestionForm = GeneralForm + " *\n" + "___________________\n";

	Question.Answer = FirstQNumber * SecondQNumber;
	break;

case Div:
	Question.QuestionForm = GeneralForm + " /\n" + "___________________\n";

	Question.Answer = FirstQNumber / SecondQNumber;
	break;
}



}
void MedQustion(stQuestionsInformation& Question) { //Fill Med Questions
short FirstQNumber = RandomNumber(10, 50), SecondQNumber = RandomNumber(1, 10);

string GeneralForm = "\n" + to_string(FirstQNumber) + "\n" + to_string(SecondQNumber);

switch (Question.Type)
{
case Add:
	Question.QuestionForm = GeneralForm + " +\n" + "___________________\n";

	Question.Answer = FirstQNumber + SecondQNumber;
	break;

case Sub:
	Question.QuestionForm = GeneralForm + " -\n" + "___________________\n";

	Question.Answer = FirstQNumber - SecondQNumber;
	break;

case Mul:
	Question.QuestionForm = GeneralForm + " *\n" + "___________________\n";

	Question.Answer = FirstQNumber * SecondQNumber;
	break;

case Div:
	Question.QuestionForm = GeneralForm + " /\n" + "___________________\n";

	Question.Answer = FirstQNumber / SecondQNumber;
	break;
}
}
void HardQustion(stQuestionsInformation& Question) { //Fill Hard Questions
short FirstQNumber = RandomNumber(10, 100), SecondQNumber = RandomNumber(10, 100);

string GeneralForm = "\n" + to_string(FirstQNumber) + "\n" + to_string(SecondQNumber);

switch (Question.Type)
{
case Add:
	Question.QuestionForm = GeneralForm + " +\n" + "___________________\n";

	Question.Answer = FirstQNumber + SecondQNumber;
	break;

case Sub:
	Question.QuestionForm = GeneralForm + " -\n" + "___________________\n";

	Question.Answer = FirstQNumber - SecondQNumber;
	break;

case Mul:
	Question.QuestionForm = GeneralForm + " *\n" + "___________________\n";

	Question.Answer = FirstQNumber * SecondQNumber;
	break;

case Div:
	Question.QuestionForm = GeneralForm + " /\n" + "___________________\n";

	Question.Answer = FirstQNumber / SecondQNumber;
	break;
}

}
void QuestionAnswerAndFormAccourdingToLevel(stQuestionsInformation &Question) { // This Function fill Question Form And Answer Accourding to its level switch (Question.Level) { case EasyQ: EasyQustion(Question); break; case MedQ: MedQustion(Question); break; case HardQ: HardQustion(Question); break; }
}
void FillQuestionInformation(stQuestionsInformation &QuestionInfo, stTestInformations TestInfo) { QuestionInfo.Level = Questionlevel(TestInfo.ExamLevel); QuestionInfo.Type = QuestionType(TestInfo.Type); QuestionAnswerAndFormAccourdingToLevel(QuestionInfo);
}
void FillAllQuestionsInfo(stQuestionsInformation Questions[100] , stTestInformations TestInfo) { for (int i = 0; i < TestInfo.QueistoinsNumber; i++) { FillQuestionInformation(Questions[i] , TestInfo); } }
void ChangeScreenColor(enTestFinalResult PassOrFail) { switch (PassOrFail) { case PASS: system("color 2F"); break;
case FAIL:
	cout << "\a";
	system("color 4F");
	break;
}

}
void AnswerDecied(int UserNumber , int RightAnswer , stTestInformations &TestInfo) { //This Procedure Deside what to do according to User Answer if Correct or Not
if (UserNumber == RightAnswer)
{
	cout << "Right Answer :-) \n";
	ChangeScreenColor(PASS);
	TestInfo.RightAnswersNumber++;
}
else
{
	cout << "Wrong Answer :-( \a\n";
	ChangeScreenColor(FAIL);
	cout << "Right Answer is : " << RightAnswer << endl;
	TestInfo.WrongAnsersNumber++;

}



}
enTestFinalResult PassOrFail(stTestInformations TestInfo) { if (TestInfo.RightAnswersNumber > TestInfo.WrongAnsersNumber) return enTestFinalResult::PASS;
// if not pass ==> Fail

return enTestFinalResult::FAIL;


}
void PASSOrFAILScreen(enTestFinalResult IsPass) { switch (IsPass) { case PASS: cout << "\n________________________________________\n";
	cout << "\n        Final Result is PASS :-)        ";

	cout << "\n________________________________________\n";
	ChangeScreenColor(PASS);

	break;

case FAIL:
	cout << "\n________________________________________\n";

	cout << "\n        Final Result is Fail :-(        \a";

	cout << "\n________________________________________\n";
	ChangeScreenColor(FAIL);
	break;

}




}
string TestTypeAsString(enTestType TestType) { switch (TestType) { case Add: return "Add"; case Sub: return "Sub"; case Mul: return "Mul"; case Div: return "Div"; case OpMix: return "Mix"; } }
string TestLevelAsString(enTestLevel TestLevel) { switch (TestLevel) { case Easy: return "Easy"; case Med: return "Med"; case Hard: return "Hard"; case LevelMix: return "Mix"; } }
void FinalResultScreen(stTestInformations TestInfo) { cout << "\n";
cout << "Number of questions : " << TestInfo.QueistoinsNumber << endl;

cout << "Questions Level : " << TestLevelAsString(TestInfo.ExamLevel) << endl;

cout << "OpType : " << TestTypeAsString(TestInfo.Type) << endl;

cout << "Number of Right Answers : " << TestInfo.RightAnswersNumber << endl;

cout << "Number of Wrong Answers : " << TestInfo.WrongAnsersNumber << endl;

cout << "\n________________________________________\n";

}
void ScreenReset() { system("CLS"); system("Color 0f"); }
int main() { srand((unsigned)time(NULL));
stTestInformations TestInfo;
char WantPlayAgain;


do

{
	TestInfo.RightAnswersNumber = 0 , TestInfo.WrongAnsersNumber = 0; 

	ScreenReset();

	TestInfo.QueistoinsNumber = ReadPositiveNumber("How many questions do you want to answer ? ");

	TestInfo.ExamLevel = TestLevel();

	TestInfo.Type = QuestionsType();

	stQuestionsInformation Questions[100];

	FillAllQuestionsInfo(Questions, TestInfo);

	int UserAnswer = 0;

	for (short TestRound = 1; TestRound <= TestInfo.QueistoinsNumber; TestRound++)
	{

		cout << "\nQuestion [" << TestRound << " / " << TestInfo.QueistoinsNumber << "]" << endl;

		//Question Accourding To level
		cout << Questions[TestRound - 1].QuestionForm;

		cin >> UserAnswer;

		//Right Or Wrong Answer
		//if Right ====> Right Answer :-) , Green Screen else ===> Wrong Answer :-( , Red Screen , Bill Sound , Right Answer
		AnswerDecied(UserAnswer, Questions[TestRound - 1].Answer, TestInfo);
	}

	TestInfo.PassOrFail = PassOrFail(TestInfo);

	PASSOrFAILScreen(TestInfo.PassOrFail);

	FinalResultScreen(TestInfo);

	do
	{
		cout << "\nDo you want to play again Y / N ? ";
		cin >> WantPlayAgain;
	} while (WantPlayAgain != 'y' && WantPlayAgain != 'Y' && WantPlayAgain != 'n' && WantPlayAgain != 'N');

} while (WantPlayAgain == 'y' || WantPlayAgain == 'Y');



return 0;

}

