#include "genericFeatures.hpp"

std::string genericFeatures::removePrefix
(
	std::string filename, 
	std::string prefix
) 
{
	int firstindex = filename.find_first_of(prefix);
	// returns what comes after first string "prefix"	 
	return filename.substr (firstindex+prefix.size(),filename.size()-(firstindex+prefix.size()));
}

std::string genericFeatures::removeSuffix
(
	std::string filename, 
	std::string suffix
) 
{
	int lastindex = filename.find_last_of(suffix);
	// returns what comes after string "suffix"	 
	return filename.substr (lastindex+suffix.size(),filename.size()-(lastindex+suffix.size()));
}

std::string genericFeatures::int2str
(
	int futurestring
) 
{
	std::ostringstream oss;
	// write the output stream
	oss << futurestring;
	return oss.str();
}

std::size_t genericFeatures::getTime
(
	void
) 
{
	std::chrono::high_resolution_clock::time_point p = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds us = std::chrono::duration_cast<std::chrono::microseconds>(p.time_since_epoch());
	return us.count();
}

bool genericFeatures::hasExtension
(
	std::string filename
) 
{
	// find last "."
	int lastindex = filename.find_last_of(".");
	// test if empty
	if (lastindex == -1) {
		return false;
	}
	// copy what comes after last dot
	std::string extension = filename.substr 
	(
		lastindex+1,
		filename.size()-(lastindex+1)
	);
	// if the length is superior to 1 character, true else false
	return (extension.size()>0) ? true : false ;
}

bool genericFeatures::isExtension
(
	std::string filename, 
	std::string extension
) 
{
	// find last "."
	int lastindex = filename.find_last_of(".");
	// copy what comes after last dot
	std::string str2 = filename.substr (lastindex+1,filename.size()-(lastindex+1));
	// loop through each character and makes it lower-case. 
	// stop at end of string (\0)
	for(int i = 0; str2[i] != '\0'; i++){
		str2[i] = tolower(str2[i]);
	}
	// return the result
	return (extension.compare(str2) == 0) ? true : false ;
}

bool genericFeatures::fileExists
(
	std::string filename
)
{
	FILE * pFile = fopen (filename.c_str(),"rb");
	if (pFile!=NULL)
	{
		fclose (pFile);
		return true;
	}
	return false;
}

unsigned long int genericFeatures::getFileSize
(
	std::string filename
) 
{
	unsigned long int size = 0;
	FILE * fp = fopen (filename.c_str(),"rb");
	if (fp!=NULL) {
		fseek (fp, 0, SEEK_END);
		size = ftell (fp);
		fclose (fp);
  	}
	return size;
}

std::string genericFeatures::getSizeUnit
(
	unsigned long int bytes
)
{
	std::string Units[] = {"bytes","Kbytes","Mbytes",
							"Gbytes","Tbytes","Pbytes", "Ebytes"};
	short divider = 0;
	for (double i=1.0;((float)(bytes))/i>1000.0;i*=1000.0) {
		divider++;
	}
	//create a stringstream
	std::stringstream converted;
	//add number to the stream
	converted << ((float)(bytes))/pow(1000.0,divider);
	//return a string with the contents of the stream
	return converted.str()+" "+Units[divider];
}

std::vector<std::string> genericFeatures::listFiles
(
	std::string path
)
{
	std::vector<std::string> PathToFiles;
	struct dirent *entry;
	DIR *dp;
//	unsigned char isFile =0x8;
	unsigned char isFolder =0x4;

	dp = opendir(path.c_str());
	if (dp == NULL) { return PathToFiles; }

	while ((entry = readdir(dp))) 
	{ 
		if (entry->d_type != isFolder) 
		{
			PathToFiles.push_back(path+"/"+entry->d_name);
		}
	}
	closedir(dp);
	return PathToFiles;
}

std::string genericFeatures::readFile
(
	std::string file
)
{

/*	std::ifstream ifs(file, std::ios::binary);
	char buff[1000];
	ifs.seekg (0, std::ios::beg);
	int count = 0;
	while(!ifs.eof()) {
		ifs.read(buff, 1000);
		std::cout << count++ << std::endl;
	}"/


class Data {
        int    key;
        double value;
    };
    
    Data x;
    Data *y = new Data[10];

    fstream myFile ("data.bin", ios::in | ios::out | ios::binary);
    myFile.seekp (location1);
    myFile.write ((char*)&x, sizeof (Data));
    ...
    myFile.seekg (0);
    myFile.read ((char*)y, sizeof (Data) * 10);

*/	std::string line;
	std::ifstream myfile (file);
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			std::getline (myfile,line);
			std::cout << line << std::endl;
    	}
		myfile.close();
	}
	else std::cout << "Unable to open file"; 
	return "bingo";
}

std::string genericFeatures::readBinaryFile 
(
		std::string file
)
{
	std::ifstream f(file, std::ios::in |std::ios::binary);
	f >> std::noskipws; // don't omit the "white spaces" c.f. ios_base -> isspace
	f.seekg(0, std::ios::end); // set the pointer at the end of file
	size_t sizeB = f.tellg(); // get the length
	f.seekg(0, std::ios::beg); // set the pointer to the beginning
	std::string binaryXML("");
	for (unsigned short i=0; i<sizeB; i++) {
		char byte;
		f.seekg(i);
		f >> byte;
		binaryXML += hexToStr((unsigned short)(byte>>4))+hexToStr((unsigned short)(byte&0x0F));
	}
	f.close();
	return binaryXML;
}

void genericFeatures::writeBinaryFile 
(
		std::string file,
		std::vector<char *> data
)
{
	std::ofstream f(file, std::ios::out|std::ios::binary|std::ios::ate );
	unsigned int size = data.size();
	for (unsigned int i = 0; i<size;i++) {
		f << (std::hex) << data.at(i);
	}
	f.close();
}

char genericFeatures::convertToBinary
(
	unsigned char HalfMSB,
	unsigned char HalfLSB
)
{
	unsigned char byte[] = {HalfMSB, HalfLSB};
	unsigned short converted = 0;
	unsigned int fullbytesize = 1;
	for (unsigned int i=0;i<=fullbytesize;i++) {
		switch(byte[i]) {
			case 49: converted += ((i==0) ? 16: 1); break;
			case 50: converted += ((i==0) ? 32: 2); break;
			case 51: converted += ((i==0) ? 48: 3); break;
			case 52: converted += ((i==0) ? 64: 4); break;
			case 53: converted += ((i==0) ? 80: 5); break;
			case 54: converted += ((i==0) ? 96: 6); break;
			case 55: converted += ((i==0) ? 112: 7); break;
			case 56: converted += ((i==0) ? 128: 8); break;
			case 57: converted += ((i==0) ? 144: 9); break;
			case 65: converted += ((i==0) ? 160: 10); break;
			case 66: converted += ((i==0) ? 176: 11); break;
			case 67: converted += ((i==0) ? 192: 12); break;
			case 68: converted += ((i==0) ? 208: 13); break;
			case 69: converted += ((i==0) ? 224: 14); break;
			case 70: converted += ((i==0) ? 240: 15); break;
			default: ;
		}
	}
	return (char)converted;
}

std::string genericFeatures::hexToStr
(
	unsigned short hex
)
{
	std::string converted;
	switch(hex) {
		case 1: converted = "1"; break;
		case 2: converted = "2"; break;
		case 3: converted = "3"; break;
		case 4: converted = "4"; break;
		case 5: converted = "5"; break;
		case 6: converted = "6"; break;
		case 7: converted = "7"; break;
		case 8: converted = "8"; break;
		case 9: converted = "9"; break;
		case 10: converted = "A"; break;
		case 11: converted = "B"; break;
		case 12: converted = "C"; break;
		case 13: converted = "D"; break;
		case 14: converted = "E"; break;
		case 15: converted = "F"; break;
		default: converted = "0" ;
	}
	return converted;
}



void genericFeatures::writeFirstBinaryFile 
(
		void
)
{
	std::ofstream f("SonyBiMMetadata.bin", std::ios::out | std::ios::binary);
	std::string data ("3C3F786D6C2076657273696F6E3D22312E302220656E636F64696E673D225554462D38223F3E0A3C4E6F6E5265616C54696D654D65746120786D6C6E733D2275726E3A736368656D61732D70726F66657373696F6E616C446973633A6E6F6E5265616C54696D654D6574613A7665722E312E31302220786D6C6E733A736F6E793D2275726E3A736368656D61732D736F6E792D636F6D3A70726F3A6E7274457874656E74696F6E3A323030332220786D6C6E733A6C69623D2275726E3A736368656D61732D70726F66657373696F6E616C446973633A6C696222206C6173745570646174653D22323030382D30392D31315430393A35383A30335A223E0A093C5461726765744D6174657269616C20756D69645265663D2230363041324233343031303130313035303130313044343331333030303030303141423030443030323034373035383030383030343630323032323130333135222F3E0A093C4475726174696F6E2076616C75653D2232343634222F3E0A093C4C74634368616E67655461626C652074634670733D223235223E0A09093C4C74634368616E6765206672616D65436F756E743D2230222076616C75653D22323230323538303922207374617475733D22696E6372656D656E74222F3E0A09093C4C74634368616E6765206672616D65436F756E743D2232343633222076616C75653D22313034313539303922207374617475733D22656E64222F3E0A093C2F4C74634368616E67655461626C653E0A093C4372656174696F6E446174652076616C75653D22323030382D30392D31315430393A35383A30335A222F3E0A093C5479706963616C556269742076616C75653D2230303030303030303030303030303030222F3E0A093C4B65794672616D65206672616D65436F756E743D2230222F3E0A093C426F6479556D696442617369634368616E67655461626C653E0A09093C426F6479556D696442617369634368616E6765206672616D65436F756E743D2230222076616C75653D223036304132423334303130313031303530313031304434333333303030303030314142303044303032303437303538303038303034363032303232313033313522207374617475733D227374617274222F3E0A093C2F426F6479556D696442617369634368616E67655461626C653E0A093C426F6479556D69645768656E4368616E67655461626C653E0A09093C426F6479556D69645768656E4368616E6765206672616D65436F756E743D2230222076616C75653D223834303636433033323034373035383022207374617475733D22696E6372656D656E74222F3E0A09093C426F6479556D69645768656E4368616E6765206672616D65436F756E743D2232343633222076616C75653D223434364536453033323034373035383022207374617475733D22656E64222F3E0A093C2F426F6479556D69645768656E4368616E67655461626C653E0A093C426F6479556D696457686572654368616E67655461626C653E0A09093C426F6479556D696457686572654368616E6765206672616D65436F756E743D2230222076616C75653D2230303030303030303030303030303030303030303030303022207374617475733D227374617274222F3E0A093C2F426F6479556D696457686572654368616E67655461626C653E0A093C426F6479556D696457686F4368616E67655461626C653E0A09093C426F6479556D696457686F4368616E6765206672616D65436F756E743D2230222076616C75653D2230303030303030303030303030303030303030303030303022207374617475733D227374617274222F3E0A093C2F426F6479556D696457686F4368616E67655461626C653E0A093C4B6C765061636B65745461626C653E0A09093C4B6C765061636B6574206672616D65436F756E743D223022206B65793D22303630453242333430313031303130353033303130323041303230303030303022206C656E67746856616C75653D22303935463532363536333533373436313732373422207374617475733D2273706F74222F3E0A093C2F4B6C765061636B65745461626C653E0A093C566964656F466F726D61743E0A09093C566964656F526563506F727420706F72743D224449474954414C2D434F4D504F4E454E54222F3E0A09093C566964656F4672616D6520766964656F436F6465633D224D50454732484433355F313434305F313038305F4D5040484C2220666F726D61744670733D22323570222F3E0A09093C566964656F4C61796F757420706978656C3D223134343022206E756D4F66566572746963616C4C696E653D22313038302220617370656374526174696F3D2231363A39222F3E0A093C2F566964656F466F726D61743E0A093C417564696F466F726D6174206E756D4F664368616E6E656C3D2234223E0A09093C417564696F526563506F727420706F72743D22414E414C4F472220617564696F436F6465633D224C50434D31362220747261636B4473743D22434831222F3E0A09093C417564696F526563506F727420706F72743D22414E414C4F472220617564696F436F6465633D224C50434D31362220747261636B4473743D22434832222F3E0A09093C417564696F526563506F727420706F72743D22414E414C4F472220617564696F436F6465633D224C50434D31362220747261636B4473743D22434833222F3E0A09093C417564696F526563506F727420706F72743D22414E414C4F472220617564696F436F6465633D224C50434D31362220747261636B4473743D22434834222F3E0A093C2F417564696F466F726D61743E0A093C53756253747265616D20636F6465633D2250442D53756253747265616D222F3E0A093C446576696365206D616E7566616374757265723D22534F4E5922206D6F64656C4E616D653D225044572D46333530222073657269616C4E6F3D223130373839223E0A09093C456C656D656E742068617264776172653D225041434B414745202020202220736F6674776172653D2256657273696F6E20312E363230222F3E0A09093C456C656D656E742068617264776172653D2253595320202020202020202220736F6674776172653D2256657273696F6E20312E363230222F3E0A09093C456C656D656E742068617264776172653D2246502020202020202020202220736F6674776172653D2256657273696F6E20312E303931222F3E0A09093C456C656D656E742068617264776172653D2254535953202020202020202220736F6674776172653D2256657273696F6E20332E303033222F3E0A09093C456C656D656E742068617264776172653D22544D4250202020202020202220736F6674776172653D2256657273696F6E20332E303031222F3E0A09093C456C656D656E742068617264776172653D224E494F53202020202020202220736F6674776172653D2256657273696F6E20312E313230222F3E0A09093C456C656D656E742068617264776172653D224F534420202020202020202220736F6674776172653D2256657273696F6E20312E353030222F3E0A09093C456C656D656E742068617264776172653D2244525620202020202020202220736F6674776172653D2256657273696F6E20312E353530222F3E0A09093C456C656D656E742068617264776172653D224453502E412020202020202220736F6674776172653D2256657273696F6E20322E303130222F3E0A09093C456C656D656E742068617264776172653D2250525856202020202020202220736F6674776172653D2256657273696F6E20312E373030222F3E0A09093C456C656D656E742068617264776172653D2250525841202020202020202220736F6674776172653D2256657273696F6E20312E303130222F3E0A09093C456C656D656E742068617264776172653D2247454F53202020202020202220736F6674776172653D2256657273696F6E20312E353030222F3E0A09093C456C656D656E742068617264776172653D224E4F5641202020202020202220736F6674776172653D2256657273696F6E20312E303031222F3E0A09093C456C656D656E742068617264776172653D2241542020202020202020202220736F6674776172653D2256657273696F6E20312E353430222F3E0A09093C456C656D656E742068617264776172653D2246524553482020202020202220736F6674776172653D2256657273696F6E20312E303530222F3E0A09093C456C656D656E742068617264776172653D22434F50524F2020202020202220736F6674776172653D2256657273696F6E20312E303530222F3E0A093C2F4465766963653E0A3C2F4E6F6E5265616C54696D654D6574613E202020202020202020202020202020202020200A");
	unsigned int size = data.size();
	for (unsigned int i = 0; i<(size/2);i++) {
		
		char byte = convertToBinary((unsigned char)data.at(2*i) ,(unsigned char)data.at((2*i)+1));
		if (i < 8) {
			std::cout << byte<<" "<<(unsigned short) byte <<" "<<(unsigned int) byte << std::endl;
		}
		
		f.write((char *)(&byte), sizeof(char));
	}
	f.close();
}
void genericFeatures::readFirstBinaryFile 
(
		void
)
{
	std::cout << std::endl;
	std::ifstream f("SonyBiMMetadata.bin", std::ios::in |std::ios::binary);
	f >> std::noskipws; // don't omit the "white spaces" c.f. ios_base -> isspace
	f.seekg(0, std::ios::end); // set the pointer at the end of file
	size_t sizeB = f.tellg(); // get the length
	f.seekg(0, std::ios::beg); // set the pointer to the beginning
	for (unsigned short i=0; i<sizeB; i++) {
		char byte;
		f.seekg(i);
		f >> byte;
		std::cout << hexToStr((unsigned short)(byte>>4)) << hexToStr((unsigned short)(byte&0x0F));
	}
	f.close();
}
