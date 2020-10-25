for (( test=0; test<10; ++test ));
do
	if(($test<10));
	then
		base_name="0"$test
	else
		base_name=$test
	fi
	echo Case: $base_name .........done
	inFile="test-cases/in"$base_name.txt;
	outFile="test-cases/out"$base_name.txt;
	touch $inFile;
	touch $outFile;
	ulimit -s unlimited
	g++ -o genInput genInput.cpp
	./genInput $test > $inFile

	g++ -o solution solution.cpp
	./solution < $inFile > $outFile
done
cd "test-cases"
zip -r test-case *