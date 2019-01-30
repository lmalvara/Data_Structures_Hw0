#Compile the code
# if the file count exits then remove it
if [ -f count ]; then
    rm count
fi
g++ -std=c++11 *.cpp -o count
# if the file count does not exit then exit the test
if [ ! -f count ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
rm *.stderr *.stdout *.diff
# For test case 1
# input 1.txt
./count "filename=1.txt" 1>1.stdout 2>1.stderr
# compare 1.stdout with 1.ans, output the difference to 1.diff
diff -iEBwu 1.ans 1.stdout > 1.diff
# if diff returns nothing, it means you pass the test case (Your ourput is correct)
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 1    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 1.diff
fi
# For test case 2
./count "filename=2.txt" 1>2.stdout 2>2.stderr
diff -iEBwu 2.ans 2.stdout > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2    \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 3
./count "filename=3.txt" 1>3.stdout 2>3.stderr
diff -iEBwu 3.ans 3.stdout > 3.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3    \033[1;92mPASSED.\033[0m"
    rm -f 3.diff
fi