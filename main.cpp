// raXORcli.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string xorIT(std::string,std::string);

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("ex: program.exe fisier.txt\n");
		return 1;
	}
	
	char* Fisier = argv[1];
	
	//printf("%s\n",Fisier);
	std::string Key = "alabala";
	//Citire din fisier
	std::string line;
	
	std::vector<std::string> DecContinut;
	
	std::ifstream fDec (Fisier);
     if (fDec.is_open())
	 {
		while ( std::getline (fDec,line) )
	   {
		   //std::cout << line << '\n';
		   DecContinut.push_back(line);

	   }
       fDec.close();
	 }else{
		printf("Nu pot deschide fisierul %s.\n",Fisier);	
		 return 1;
	 }

 
	//scrie in fisier
      std::string fEncNume = std::string(Fisier);
	  fEncNume += ".Enc.txt";
	  
	  
	  std::ofstream fEnc;
	  fEnc.open (fEncNume.c_str());
	  for(int i=0;i<DecContinut.size();i++)
	  {
		  fEnc << xorIT(Key,DecContinut[i]) << "\n";
	  }
	  fEnc.close();

	printf("Done , acum spargema!\nAm scris si in fisierul %s\n",fEncNume.c_str());
	system("pause");
	return 0;

}

std::string xorIT(std::string Key,std::string Dec)
{

	int LungimeCheie = Key.length();
	for(int i=0;i<Dec.length();i++)
	{
		Dec[i] = Dec[i] ^ Key[i%LungimeCheie];
	}

	return Dec;
}
