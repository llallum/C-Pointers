#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>
#include <stddef.h>

using namespace std;

int main()
{

    DWORD EntryPoint;
    DWORD* pEntryPoint;
    DWORD MagicNumber;
    DWORD* pointer;
    //DWORD *pSectionName;
    //DWORD * sizeOptional_header;
    //pSectionName = &SectionName;
    pEntryPoint = &EntryPoint;

    IMAGE_DOS_HEADER* pDosHeader = (IMAGE_DOS_HEADER*)GetModuleHandle(NULL);
    IMAGE_NT_HEADERS* pNTHeaders = (IMAGE_NT_HEADERS*)((BYTE*)pDosHeader + pDosHeader->e_lfanew);
    EntryPoint = pNTHeaders->OptionalHeader.AddressOfEntryPoint;
    MagicNumber = pNTHeaders->FileHeader.Machine;
    //MagicNumber =
    IMAGE_SECTION_HEADER * pSectionName = (IMAGE_SECTION_HEADER*)((char*)pNTHeaders + pNTHeaders->FileHeader.SizeOfOptionalHeader + sizeof(IMAGE_FILE_HEADER) + 4); //+4 to skip the PE/0/0

    cout<< pSectionName->Name <<endl;


    cout <<"EntryPoint: "<< std::hex << EntryPoint <<endl;
    cout <<"Magic Number: "<< MagicNumber <<endl<<endl;



    cout<<pNTHeaders->FileHeader.NumberOfSections;

    for (int a = 0; a<pNTHeaders->FileHeader.NumberOfSections;a++)
    {
    cout <<"----------------IMAGE_SECTION_HEADER----------------"<<endl<<endl;
    cout <<"Virtual Address: "<< (BYTE*)((char*)(pSectionName+a))<<endl;
    cout <<"Virtual Address: "<<pSectionName+a <<endl;
    cout <<"Section Name: "<<(BYTE*)(pSectionName+a) <<endl;
    cout <<"Pointer to Raw Data: "<< (pSectionName+a)->PointerToRawData <<endl;
    cout <<"Size of Raw Data: "<< (pSectionName+a)->SizeOfRawData<<endl;
    cout <<"VirtualAddress: "<<(pSectionName+a)->VirtualAddress<<endl;
    cout <<"Pointer to Relocations: "<<(pSectionName+a)->PointerToRelocations<<endl;
    cout <<"Pointer to Line Numbers: "<<(pSectionName+a)->PointerToLinenumbers<<endl;
    cout <<"Number of Relocations: " << std::hex << (pSectionName+a)->Characteristics <<endl;


  //cout <<"Physical Address: "<<pSectionName->PhysicalAddress<<endl;
   // system("PAUSE");

    return 0;
}
