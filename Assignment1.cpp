//Jillian Anderson
//2317772
//Data Structures Section 3
//Assignment 1

//first you have to import everything you will need to make the program
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
//this piece of code is so you dont have to type of std:: every time you want the standard
using namespace std;


//this the method for calculating variance, the parameters are the file, the mean, and the number of lines
float varianceCalc(string file,float mean, int numlines)
{
    //start and open the file stream
    ifstream thisstream;

    thisstream.open(file);

    //these next few lines are the equation for the variance
    string line;
    float sumDifference = 0;

    while(getline(thisstream, line))
    {
        sumDifference += pow(line.length() - mean,2);

    }


    float variance = sumDifference/(numlines-1);
    //return the variance
    return variance;


}
//method for calculating the gaussian number
float gaussianCalc(float mean, float variance)
{
//the equation
    float a = (float) rand()/ (float)RAND_MAX;
    float b = (float) rand()/ (float)RAND_MAX;
    float c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
    float d = sqrt(variance) * c + mean;
//gaussian number is returned
    return d;
}

//main method
int main(int argc, char** argv)
{
    srand(time(NULL));
    //start a file stream between the program and the file
    ifstream filestreamer;
    //the output will be written into this file
    ofstream outputFileStream("JillianAnderson.txt");
    //make sure there is an arguement to use
    if (argc >= 1)
    {
        // first assign the command line argument to a string called file name
        string thisFile = argv[1];
//start the while loop that is going to allow for multiple entries
while(thisFile!="0") {
        //open the file
        filestreamer.open(thisFile);
        //check to make sure there was no problems opening the file and if there was end the program

        if(filestreamer.fail())
        {
            cout << "Could not open the file!" << endl;
            //exit the program if there was a problem opening the file
            exit(1);

        }
        //declaration of many of the variables
        string fullText;
        int numOfLines = 0;
        float sum = 0;
        int cCount = 0;
        int aCount = 0;
        int tCount = 0;
        int gCount = 0;
        string fileLine;
        int bigramCount = 0;
        float mean;
        float variance;
        float standDeviation;

        float aaCount = 0, ccCount = 0, ttCount = 0, ggCount = 0;
        float acCount = 0, atCount = 0, agCount = 0;
        float caCount = 0, ctCount = 0, cgCount = 0;
        float taCount = 0, tcCount = 0, tgCount = 0;
        float gaCount = 0, gcCount = 0, gtCount = 0;

        float cProb = 0;
        float aProb = 0;
        float tProb = 0;
        float gProb = 0;

        float ccProb = 0, aaProb = 0, ttProb = 0, ggProb = 0;
        float acProb = 0, atProb = 0, agProb = 0;
        float caProb = 0, ctProb = 0, cgProb = 0;
        float taProb = 0, tcProb = 0, tgProb = 0;
        float gaProb = 0, gcProb = 0, gtProb = 0;

//to the output stream, all my info
outputFileStream << "Jillian Anderson" << endl << "2317772" << endl << "Data Structures Section 3" << endl << "Assignment 1" << endl;

outputFileStream << endl;
//print the name of the file that you are analyzing
outputFileStream << "File name: " << thisFile << endl;
//while there exists another line in the file
        while(getline(filestreamer, fileLine))
        {
            //first add the length of the line of DNA in question to a sum variable
            sum += fileLine.length();
            //also increment the number of lines variable
            numOfLines++;
            //now a for loop is used to change the line to lower case so its all one case
            for(int i = 0; i < fileLine.length(); i++)
            {
                fileLine[i] = tolower(fileLine[i]);
            }
            //now a for loop is used to iterate through the line to collect the data
            for (int i = 0; i < fileLine.length(); i++)
            {
                //use char to get the info letter by letter and check what letter it is
                char letter = fileLine[i];

                //if its a c it will pass through here
                if(letter == 'c')
                {
                    cCount++;
                    //increment the c count and then check to see if the letter after it is also a c making it a cc bigram
                    if(fileLine[i+1] == 'c')
                    {
                        //if so increment the cc bigram count
                        ccCount+= 1;

                        //also increment the total bigram count so we can tell at the end how many bigrams we had
                        bigramCount+= 1;
                    }
                    //do this do this again for ca
                    else if(fileLine[i+1] == 'a')
                    {
                        caCount+= 1;
                        bigramCount+= 1;
                    }
                    //do this again for ct
                    else if(fileLine[i+1] == 't')
                    {
                        ctCount+= 1;
                        bigramCount+= 1;
                    }
                    //do this again for cg
                    else if(fileLine[i+1] == 'g')
                    {
                        cgCount+= 1;
                        bigramCount+= 1;
                    }

                }
                //now move onto a and do everything you did for c but for a
                if(letter == 'a')
                {
                    aCount+= 1;
                    if(fileLine[i+1] == 'c')
                    {
                        acCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 'a')
                    {
                        aaCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 't')
                    {
                        atCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 'g')
                    {
                        agCount+= 1;
                        bigramCount+= 1;
                    }
                }
                //do everything again for t
                if(letter == 't')
                {
                    tCount++;
                    if(fileLine[i+1] == 'c')
                    {
                        tcCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 'a')
                    {
                        taCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 't')
                    {
                        ttCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 'g')
                    {
                        tgCount+= 1;
                        bigramCount+= 1;
                    }
                }
                //and lastly do everything again for g
                if(letter == 'g')
                {
                    gCount++;
                    if(fileLine[i+1] == 'c')
                    {
                        gcCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 'a')
                    {
                        gaCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 't')
                    {
                        gtCount+= 1;
                        bigramCount+= 1;
                    }
                    else if(fileLine[i+1] == 'g')
                    {
                        ggCount+= 1;
                        bigramCount+= 1;
                    }
                }
            }

        }




        //now you have collected the data on the file so you can work with it now

        //calculate the probabilities for each individual nucleotide (a,c,t,g)
        cProb = (cCount/sum) * 100;
        aProb = (aCount/sum) * 100;
        tProb = (tCount/sum) * 100;
        gProb = (gCount/sum) * 100;

        //now calculate the probabilities of getting certain bigrams
        ccProb = (ccCount/bigramCount) * 100;
        aaProb = (aaCount/bigramCount) * 100;
        ttProb = (ttCount/bigramCount) * 100;
        ggProb = (ggCount/bigramCount) * 100;
        acProb = (acCount/bigramCount) * 100;
        atProb = (atCount/bigramCount) * 100;
        agProb = (agCount/bigramCount) * 100;
        caProb = (caCount/bigramCount) * 100;
        ctProb = (ctCount/bigramCount) * 100;
        cgProb = (cgCount/bigramCount) * 100;
        taProb = (taCount/bigramCount) * 100;
        tcProb = (tcCount/bigramCount) * 100;
        tgProb = (tgCount/bigramCount) * 100;
        gaProb = (gaCount/bigramCount) * 100;
        gcProb = (gcCount/bigramCount) * 100;
        gtProb = (gtCount/bigramCount) * 100;

//calculate the mean number of letters in each line
        mean = sum/numOfLines;
//use variance method to calculate the variance
        variance = varianceCalc(thisFile, mean, numOfLines);
//use varience to get the standard deviation
        standDeviation = sqrt(variance);





//now output everything to the file JillianAnderson
        outputFileStream << "The number of C's are " << cCount << endl;

        outputFileStream << "The number of A's are " << aCount << endl;

        outputFileStream << "The number of T's are " << tCount << endl;

        outputFileStream << "The number of G's are " << gCount << endl;

        outputFileStream << "The number of lines in your file is " << numOfLines << endl;

        outputFileStream << "The sum is " << sum << endl;

        outputFileStream << endl;

        outputFileStream << "The probability of getting C is " << cProb << "%" << endl;
        outputFileStream << "The probability of getting A is " << aProb << "%" << endl;
        outputFileStream << "The probability of getting T is " << tProb << "%" << endl;
        outputFileStream << "The probability of getting G is " << gProb << "%" << endl;

        outputFileStream << endl;

        outputFileStream << "The probability of getting CC is " << ccProb << "%" << endl;
        outputFileStream << "The probability of getting AA is " << aaProb << "%" << endl;
        outputFileStream << "The probability of getting TT is " << ttProb << "%" << endl;
        outputFileStream << "The probability of getting GG is " << ggProb << "%" << endl;

        outputFileStream << "The probability of getting AC is " << acProb << "%" << endl;
        outputFileStream << "The probability of getting AT is " << atProb << "%" << endl;
        outputFileStream << "The probability of getting AG is " << agProb << "%" << endl;

        outputFileStream << "The probability of getting CA is " << caProb << "%" << endl;
        outputFileStream << "The probability of getting CT is " << ctProb << "%" << endl;
        outputFileStream << "The probability of getting CG is " << cgProb << "%" << endl;

        outputFileStream << "The probability of getting TA is " << taProb << "%" << endl;
        outputFileStream << "The probability of getting TC is " << tcProb << "%" << endl;
        outputFileStream << "The probability of getting TG is " << tgProb << "%" << endl;

        outputFileStream << "The probability of getting GA is " << gaProb << "%" << endl;
        outputFileStream << "The probability of getting GC is " << gcProb << "%" << endl;
        outputFileStream << "The probability of getting GT is " << gtProb << "%" << endl;

        outputFileStream << endl;

        outputFileStream << "The mean is " << mean << endl;

        outputFileStream << "The variance is " << variance << endl;

        outputFileStream << "The standard deviation is " << standDeviation << endl;

//use gaussian method to get the number
        outputFileStream << "Gaussian: " << gaussianCalc(mean, variance) << endl;

//use a for loop to print out the 1000 letter new DNA sequence
        for( int i = 0; i < 1000; i++)
        {
//get the gaussian number using method store as float
            float gaussian = gaussianCalc(mean, variance);
//use the A probability and gaussian number to get how many As you need
            int anew = (aProb * gaussian)/100;
//use the C probability and gaussian number to get how many Cs you need
            int cnew = (cProb * gaussian)/100;
//use the T probability and gaussian number to get how many Ts you need
            int tnew = (tProb * gaussian)/100;
//use the G probability and gaussian number to get how many Gs you need
            int gnew = (gProb * gaussian)/100;
//create a place to store what is going to be put in the file
            string toFile = " ";
//for however many As you need put that many into the toFile variable
            for(int i = 0; i < anew; i++)
            {
                toFile += "A";
            }
//same as above with c
            for(int i = 0; i < cnew; i++)
            {
                toFile += "C";
            }
//same as above with T
            for(int i = 0; i < tnew; i++)
            {
                toFile += "T";
            }
//same as above with g
            for(int i = 0; i < gnew; i++)
            {
                toFile += "G";
            }
//output the results to the file
            outputFileStream << endl;

            outputFileStream << toFile << endl;



        }
//close the input file streamer
        filestreamer.close();
//now ask if they want to input another file
            cout << "Do you want to enter another file? (1 for yes or 2 for no)" << endl;
            int answer;
            cin >> answer;
            if(answer == 1)
            {
                cout << "Okay great, please enter another file name: " << endl;
                //if yes assign new file name as thisFile so when it goes back up to the top of the while loop it can enter again
                cin >> thisFile;

            }
            if(answer == 2)
            {
                cout << "Okay goodbye" << endl;
                //if no assign thisFile to "0" so that the while loop will not be entered again
                thisFile = "0";
            }
        }
    }

}
