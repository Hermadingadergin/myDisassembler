// myDisassembler.cpp : Defines the entry point for the application.
//
#include <fstream>
#include <iostream>
#include <string>
#include <list>	

#include "myDisassembler.h"

using namespace std;

void getParts(string &readLine, string &readBinary, string &rs, string &rt, string &rd, string &shamt, int &immediate, string &address)
{
	rs = "";
	rt = "";
	rd = "";
	shamt = "";
	immediate = 0;
	address = "";
	int counter = 15;
	for (int i = 0; i <= 4; i++)
	{
		rs += (readBinary[6 + i]);
		rt += (readBinary[11 + i]);
		rd += (readBinary[16 + i]);
		shamt += (readBinary[21 + i]);
	}
	for (int i = 16; i <= 31; i++)
	{
		if (readBinary[i] == '1')
		{
			immediate = immediate + pow(2, counter);
		}
		counter--;
	}
	for (int i = 16; i <= 31; i++)
	{
		address += (readBinary[i]);
	}
	//for (int i = 5; i <= 8; i++)
	//{
	//	address += (readLine[i]);
	//}
	//for (int i = 16; i <= 31; i++)
	//{
	//	address[i-16] += (readBinary[i]);
	//}
}

string toRegister(string &registerinbinary)
{
	string output;
	if (registerinbinary == "00000")
	{
		output = "$0";
	}
	if (registerinbinary == "00001")
	{
		output = "$at";
	}
	if (registerinbinary == "00010")
	{
		output = "$v0";
	}
	if (registerinbinary == "00011")
	{
		output = "$v1";
	}
	if (registerinbinary == "00100")
	{
		output = "$a0";
	}
	if (registerinbinary == "00101")
	{
		output = "$a1";
	}
	if (registerinbinary == "00110")
	{
		output = "$a2";
	}
	if (registerinbinary == "00111")
	{
		output = "$a3";
	}
	if (registerinbinary == "01000")
	{
		output = "$t0";
	}
	if (registerinbinary == "01001")
	{
		output = "$t1";
	}
	if (registerinbinary == "01010")
	{
		output = "$t2";
	}
	if (registerinbinary == "01011")
	{
		output = "$t3";
	}
	if (registerinbinary == "01100")
	{
		output = "$t4";
	}
	if (registerinbinary == "01101")
	{
		output = "$t5";
	}
	if (registerinbinary == "01110")
	{
		output = "$t6";
	}
	if (registerinbinary == "01111")
	{
		output = "$t7";
	}
	if (registerinbinary == "10000")
	{
		output = "$s0";
	}
	if (registerinbinary == "10001")
	{
		output = "$s1";
	}
	if (registerinbinary == "10010")
	{
		output = "$s2";
	}
	if (registerinbinary == "10011")
	{
		output = "$s3";
	}
	if (registerinbinary == "10100")
	{
		output = "$s4";
	}
	if (registerinbinary == "10101")
	{
		output = "$s5";
	}
	if (registerinbinary == "10110")
	{
		output = "$s6";
	}
	if (registerinbinary == "10111")
	{
		output = "$s7";
	}
	if (registerinbinary == "11000")
	{
		output = "$t8";
	}
	if (registerinbinary == "11001")
	{
		output = "$t9";
	}
	if (registerinbinary == "11010")
	{
		output = "$k0";
	}
	if (registerinbinary == "11011")
	{
		output = "$k1";
	}
	if (registerinbinary == "11100")
	{
		output = "$gp";
	}
	if (registerinbinary == "11101")
	{
		output = "$sp";
	}
	if (registerinbinary == "11110")
	{
		output = "$fp";
	}
	if (registerinbinary == "11111")
	{
		output = "$ra";
	}
	return output;
}

string toBinary(string input, bool &charbound)
{
	string output = "";
	for (int i = 0; i < 8; i++)
	{
		if (input[i] == '0')
		{
			output.append("0000");
		}
		else
		{
			if (input[i] == '1')
			{
				output.append("0001");
			}
			else
			{
				if (input[i] == '2')
				{
					output.append("0010");
				}
				else
				{
					if (input[i] == '3')
					{
						output.append("0011");
					}
					else
					{
						if (input[i] == '4')
						{
							output.append("0100");
						}
						else
						{
							if (input[i] == '5')
							{
								output.append("0101");
							}
							else
							{
								if (input[i] == '6')
								{
									output.append("0110");
								}
								else
								{
									if (input[i] == '7')
									{
										output.append("0111");
									}
									else
									{
										if (input[i] == '8')
										{
											output.append("1000");
										}
										else
										{
											if (input[i] == '9')
											{
												output.append("1001");
											}
											else
											{
												if (input[i] == 'a' || input[i] == 'A')
												{
													output.append("1010");
												}
												else
												{
													if (input[i] == 'b' || input[i] == 'B')
													{
														output.append("1011");
													}
													else
													{
														if (input[i] == 'c' || input[i] == 'C')
														{
															output.append("1100");
														}
														else
														{
															if (input[i] == 'd' || input[i] == 'D')
															{
																output.append("1101");
															}
															else
															{
																if (input[i] == 'e' || input[i] == 'E')
																{
																	output.append("1110");
																}
																else
																{
																	if (input[i] == 'f' || input[i] == 'F')
																	{
																		output.append("1111");
																	}
																	else
																	{
																		output.append("");
																		charbound = false;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return output;
}

int main()
{
	ifstream inputFile("test_case3.obj"); // ENTER INPUT FILE HERE (test_case1.obj, test_case2.obj, etc.)


    if (!inputFile.is_open())
	{
        cerr << "Error opening the input file!" << endl;
        return 1;
    }

	bool assemblable = true;
	int linenumber = 1;
    string readLine;
	string readBinary;
	string outputLine;
	string readBinary6;
	string readBinary6last;
	
	string rs;
	string rt;
	string rd;
	string shamt;
	int immediate;
	string address;
	string addressLine;

	list<string> assemblyList;
	list<int> addressinsert;
	list<string> addresses;

	bool charbound;
	while (getline(inputFile, readLine))
	{
		for (int i = 0; i < readLine.size(); i++)
		{
			if (isupper(readLine[i]) != 0)
			{
				tolower(readLine[i]);
			}
		}
		charbound = true;
		readBinary = "";
		readBinary = toBinary(readLine, charbound);
		outputLine = "";
		readBinary6 = "";
		readBinary6last = "";
		addressLine = "";
		
		if (readLine.size() != 8 || !charbound)
		{
			outputLine = "Cannot dissasemble " + readLine + " at line " + to_string(linenumber) + ".\n";
			cout << outputLine;
			assemblable = false;
		}
		else
		{
			getParts(readLine, readBinary, rs, rt, rd, shamt, immediate, address);
			for (int i = 0; i <= 5; i++)
			{
				readBinary6 += (readBinary[i]);
			}
			for (int i = 26; i <= 31; i++)
			{
				readBinary6last += (readBinary[i]);
			}
			if (readBinary6 == "101000")
			{
				outputLine = "sb " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
			}
			else
			{
				if (readBinary6 == "111000")
				{
					outputLine = "sc " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
				}
				else
				{
					if (readBinary6 == "101001")
					{
						outputLine = "sh " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
					}
					else
					{
						if (readBinary6 == "101011")
						{
							outputLine = "sw " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
						}
						else
						{
							if (readBinary6 == "100100")
							{
								outputLine = "lbu " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
							}
							else
							{
								if (readBinary6 == "100101")
								{
									outputLine = "lhu " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
								}
								else
								{
									if (readBinary6 == "110000")
									{
										outputLine = "ll " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
									}
									else
									{
										if (readBinary6 == "100011")
										{
											outputLine = "lw " + toRegister(rt) + ", " + to_string(immediate) + "(" + toRegister(rs) + ")";
										}
										else
										{
											if (readBinary6 == "001000")
											{
												outputLine = "addi " + toRegister(rt) + ", " + toRegister(rs) + ", " + to_string(immediate);
											}
											else
											{
												if (readBinary6 == "001001")
												{
													outputLine = "addiu " + toRegister(rt) + ", " + toRegister(rs) + ", " + to_string(immediate);
												}
												else
												{
													if (readBinary6 == "001100")
													{
														outputLine = "andi " + toRegister(rt) + ", " + toRegister(rs) + ", " + to_string(immediate);
													}
													else
													{
														if (readBinary6 == "000100")
														{
															int wheretoplug;
															immediate = 0;
															string addressjump;
															if (address[0] == '0') // positive
															{
																for (int i = 0; i <= 15; i++)
																{
																	if (address[i] == '1')
																	{
																		immediate = immediate + pow(2, 15 - i);
																	}
																}
																immediate = immediate + linenumber;
																wheretoplug = immediate;
																immediate *= 4;
																while (immediate != 0)
																{
																	int remainder = 0;
																	char hex;
																	remainder = immediate % 16;
																	if (remainder < 10)
																	{
																		hex = remainder + 48;
																	}
																	else
																	{
																		hex = remainder + 55;
																	}
																	addressjump += hex;
																	immediate = immediate / 16;
																}
																int i = 0;
																int j = addressjump.size() - 1;
																while (i <= j)
																{
																	swap(addressjump[i], addressjump[j]);
																	i++;
																	j--;
																}
																while (addressjump.size() < 4)
																{
																	addressjump = "0" + addressjump;
																}
															}
															else // negative
															{
																string readBinary16last;
																for (int i = 16; i <= 31; i++)
																{
																	readBinary16last += readBinary[i];
																}
																for (int i = 0; i < 16; i++)
																{
																	if (readBinary16last[i] == '1')
																	{
																		readBinary16last[i] = '0';
																	}
																	else
																	{
																		readBinary16last[i] = '1';
																	}
																}
																int j;
																for (j = 15; j >= 0; j--)
																{
																	if (readBinary16last[j] == '1')
																	{
																		readBinary16last[j] = '0';
																	}
																	else
																	{
																		readBinary16last[j] = '1';
																		break;
																	}
																}
																if (j == -1)
																{
																	string one = "1";
																	readBinary16last = one + readBinary16last;
																}
																for (int i = 0; i <= 15; i++)
																{
																	if (readBinary16last[i] == '1')
																	{
																		immediate = immediate + pow(2, 15 - i);
																	}
																}
																immediate *= -1;
																immediate = immediate + linenumber;
																wheretoplug = immediate;
																immediate *= 4;
																while (immediate != 0)
																{
																	int remainder = 0;
																	char hex;
																	remainder = immediate % 16;
																	if (remainder < 10)
																	{
																		hex = remainder + 48;
																	}
																	else
																	{
																		hex = remainder + 55;
																	}
																	addressjump += hex;
																	immediate = immediate / 16;
																}
																int i = 0;
																j = addressjump.size() - 1;
																while (i <= j)
																{
																	swap(addressjump[i], addressjump[j]);
																	i++;
																	j--;
																}
																while (addressjump.size() < 4)
																{
																	addressjump = "0" + addressjump;
																}
															}
															outputLine = "beq " + toRegister(rs) + ", " + toRegister(rt) + ", Address_" + addressjump;
															addressLine = "Address_" + addressjump;
															if (addresses.empty())
															{
																addresses.push_back(addressLine);
																addressinsert.push_back(wheretoplug);
															}
															else
															{
																bool alreadyinthere = false;
																list<string>::iterator it1 = addresses.begin();
																list<int>::iterator it2 = addressinsert.begin();
																int size = addresses.size();
																for (int i = 0; i < size; i++)
																{
																	if (*it1 == addressLine)
																	{
																		alreadyinthere = true;
																	}
																	advance(it1, 1);
																}
																if (!alreadyinthere)
																{
																	addresses.push_back(addressLine);
																	addressinsert.push_back(wheretoplug);
																}
															}
														}
														else
														{
															if (readBinary6 == "000101")
															{
																int wheretoplug;
																immediate = 0;
																string addressjump;
																if (address[0] == '0') // positive
																{
																	for (int i = 0; i <= 15; i++)
																	{
																		if (address[i] == '1')
																		{
																			immediate = immediate + pow(2, 15 - i);
																		}
																	}
																	immediate = immediate + linenumber;
																	wheretoplug = immediate;
																	immediate *= 4;
																	while (immediate != 0)
																	{
																		int remainder = 0;
																		char hex;
																		remainder = immediate % 16;
																		if (remainder < 10)
																		{
																			hex = remainder + 48;
																		}
																		else
																		{
																			hex = remainder + 55;
																		}
																		addressjump += hex;
																		immediate = immediate / 16;
																	}
																	int i = 0;
																	int j = addressjump.size() - 1;
																	while (i <= j)
																	{
																		swap(addressjump[i], addressjump[j]);
																		i++;
																		j--;
																	}
																	while (addressjump.size() < 4)
																	{
																		addressjump = "0" + addressjump;
																	}
																}
																else // negative
																{
																	string readBinary16last;
																	for (int i = 16; i <= 31; i++)
																	{
																		readBinary16last += readBinary[i];
																	}
																	for (int i = 0; i < 16; i++)
																	{
																		if (readBinary16last[i] == '1')
																		{
																			readBinary16last[i] = '0';
																		}
																		else
																		{
																			readBinary16last[i] = '1';
																		}
																	}
																	int j;
																	for (j = 15; j >= 0; j--)
																	{
																		if (readBinary16last[j] == '1')
																		{
																			readBinary16last[j] = '0';
																		}
																		else
																		{
																			readBinary16last[j] = '1';
																			break;
																		}
																	}
																	if (j == -1)
																	{
																		string one = "1";
																		readBinary16last = one + readBinary16last;
																	}
																	for (int i = 0; i <= 15; i++)
																	{
																		if (readBinary16last[i] == '1')
																		{
																			immediate = immediate + pow(2, 15 - i);
																		}
																	}
																	immediate *= -1;
																	immediate = immediate + linenumber;
																	wheretoplug = immediate;
																	immediate *= 4;
																	while (immediate != 0)
																	{
																		int remainder = 0;
																		char hex;
																		remainder = immediate % 16;
																		if (remainder < 10)
																		{
																			hex = remainder + 48;
																		}
																		else
																		{
																			hex = remainder + 55;
																		}
																		addressjump += hex;
																		immediate = immediate / 16;
																	}
																	int i = 0;
																	j = addressjump.size() - 1;
																	while (i <= j)
																	{
																		swap(addressjump[i], addressjump[j]);
																		i++;
																		j--;
																	}
																	while (addressjump.size() < 4)
																	{
																		addressjump = "0" + addressjump;
																	}
																}
																outputLine = "bne " + toRegister(rs) + ", " + toRegister(rt) + ", Address_" + addressjump;
																addressLine = "Address_" + addressjump;
																if (addresses.empty())
																{
																	addresses.push_back(addressLine);
																	addressinsert.push_back(wheretoplug);
																}
																else
																{
																	bool alreadyinthere = false;
																	list<string>::iterator it1 = addresses.begin();
																	list<int>::iterator it2 = addressinsert.begin();
																	int size = addresses.size();
																	for (int i = 0; i < size; i++)
																	{
																		if (*it1 == addressLine)
																		{
																			alreadyinthere = true;
																		}
																		advance(it1, 1);
																	}
																	if (!alreadyinthere)
																	{
																		addresses.push_back(addressLine);
																		addressinsert.push_back(wheretoplug);
																	}
																}
															}
															else
															{
																if (readBinary6 == "001111")
																{
																	outputLine = "lui " + toRegister(rt) + ", " + to_string(immediate);
																}
																else
																{
																	if (readBinary6 == "001101")
																	{
																		outputLine = "ori " + toRegister(rt) + ", " + toRegister(rs) + ", " + to_string(immediate);
																	}
																	else
																	{
																		if (readBinary6 == "001010")
																		{
																			outputLine = "slti " + toRegister(rt) + ", " + toRegister(rs) + ", " + to_string(immediate);
																		}
																		else
																		{
																			if (readBinary6 == "001011")
																			{
																				outputLine = "sltiu " + toRegister(rt) + ", " + toRegister(rs) + ", " + to_string(immediate);
																			}
																			else
																			{
																				if (readBinary6 == "000000" && readBinary6last == "100000")
																				{
																					outputLine = "add " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																				}
																				else
																				{
																					if (readBinary6 == "000000" && readBinary6last == "100001")
																					{
																						outputLine = "addu " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																					}
																					else
																					{
																						if (readBinary6 == "000000" && readBinary6last == "100100")
																						{
																							outputLine = "and " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																						}
																						else
																						{
																							if (readBinary6 == "000000" && readBinary6last == "100111")
																							{
																								outputLine = "nor " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																							}
																							else
																							{
																								if (readBinary6 == "000000" && readBinary6last == "100101")
																								{
																									outputLine = "or " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																								}
																								else
																								{
																									if (readBinary6 == "000000" && readBinary6last == "101010")
																									{
																										outputLine = "slt " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																									}
																									else
																									{
																										if (readBinary6 == "000000" && readBinary6last == "101011")
																										{
																											outputLine = "sltu " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																										}
																										else
																										{
																											if (readBinary6 == "000000" && readBinary6last == "000000")
																											{
																												immediate = 0;
																												for (int i = 0; i <= 4; i++)
																												{
																													if (shamt[i] == '1')
																													{
																														immediate = immediate + pow(2, 4 - i);
																													}
																												}
																												outputLine = "sll " + toRegister(rd) + ", " + toRegister(rt) + ", " + to_string(immediate);
																											}
																											else
																											{
																												if (readBinary6 == "000000" && readBinary6last == "000010")
																												{
																													immediate = 0;
																													for (int i = 0; i <= 4; i++)
																													{
																														if (shamt[i] == '1')
																														{
																															immediate = immediate + pow(2, 4 - i);
																														}
																													}
																													outputLine = "srl " + toRegister(rd) + ", " + toRegister(rt) + ", " + to_string(immediate);
																												}
																												else
																												{
																													if (readBinary6 == "000000" && readBinary6last == "100010")
																													{
																														outputLine = "sub " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																													}
																													else
																													{
																														if (readBinary6 == "000000" && readBinary6last == "100011")
																														{
																															outputLine = "subu " + toRegister(rd) + ", " + toRegister(rs) + ", " + toRegister(rt);
																														}
																														else
																														{
																															outputLine = "Cannot dissasemble " + readLine + " at line " + to_string(linenumber) + ".\n";
																															cout << outputLine;
																															assemblable = false;
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (assemblable)
		{
			assemblyList.push_back(outputLine);
		}
		linenumber++;
	}
	if (assemblable)
	{
		ofstream outputFile("testfile3.s"); // 	ENTER OUTPUT FILE HERE
		if (!outputFile.is_open())
		{
			cerr << "Error opening the output file!" << endl;
			return 1;
		}
		//assemblyList.reverse();



		int counter = 0;
		while (!addresses.empty())
		{
			list<string>::iterator it1 = assemblyList.begin();
			advance(it1, counter + addressinsert.back());
			assemblyList.insert(it1, addresses.back());
			addresses.pop_back();
			addressinsert.pop_back();
			counter++;
		}


		assemblyList.reverse();
		while (!assemblyList.empty())
		{
			outputFile << assemblyList.back() << "\n";
			assemblyList.pop_back();
		}

	}
}

