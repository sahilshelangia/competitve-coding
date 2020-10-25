#Design Structure for new Question
cd /home/hackerearth/Desktop/HackerEarth/Setter/
read -p "Enter problem name: " ques_name
if [ -d "$ques_name" ]; then
	read -p "Directory already exist. Press 1 to replace. Press 0 to exit." choice
	if test $choice -eq 1
	then
		#no issue
		rm -r $ques_name
	else
		exit;
	fi
fi

mkdir $ques_name
cd $ques_name

cp /home/hackerearth/Desktop/HackerEarth/TestCaseScript/main.sh main.sh
cp /home/hackerearth/Desktop/HackerEarth/TestCaseScript/sampleOutput.txt sampleOutput.txt
cp /home/hackerearth/Desktop/HackerEarth/TestCaseScript/sampleInput.txt sampleInput.txt
cp /home/hackerearth/Desktop/HackerEarth/TestCaseScript/solution.cpp solution.cpp
cp /home/hackerearth/Desktop/HackerEarth/TestCaseScript/genInput.cpp genInput.cpp
mkdir "test-cases"

subl sampleInput.txt
subl sampleOutput.txt
subl solution.cpp
subl genInput.cpp
subl main.sh

exec bash