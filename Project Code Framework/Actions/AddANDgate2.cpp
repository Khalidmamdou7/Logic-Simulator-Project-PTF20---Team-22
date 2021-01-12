#include "AddANDgate2.h"
#include "..\ApplicationManager.h"
AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	 pOut = pManager->GetOutput();
	 pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");
	
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//check if within drawing area
	while (!(Cy > UI.ToolBarHeight +UI.GateBarHeight + UI.AND2_Width / 2 && Cy < (UI.height - UI.StatusBarHeight) - UI.AND2_Width / 2))
	{
		pOut->PrintMsg("You are not allowed to print your label outside the drawing area, choose your place again...");
		pIn->GetPointClicked(Cx, Cy);
	}
	
	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	AND2 *pA=new AND2(GInfo, AND2_FANOUT); 
	pManager->AddComponent(pA);
	//ahmed
	//add label
	/*
	string str = "Add component  (AND) label : "; //ahmed
	AND2Name = pIn->GetSrting(pOut, str, "");   //ahmed 
	pA->setlabel(AND2Name);
	//string label = pA->getlabel();
	const char* cpText = AND2Name.c_str();
	pOut->Printstringg(Cx, Cy, cpText);
	pOut->ClearStatusBar(); pManager->UpdateInterface();
	//strcpy(cpText, AND2Name.c_str());
	//Selected->setlabel(pIn->GetSrting(pOut, str2, ""));
	//string label = Selected->getlabel();
	//const char* cpText = label.c_str();
	//	strcpy(cpText, str2.c_str());
	//pOut->Printstringg(Cx, Cy, cpText);
	//pOut->ClearStatusBar();
	//try me
	//pIn->GetPointClicked(Cx, Cy);
	//if (GInfo.x1 < Cx < GInfo.x2) {
		//edit label when label is bresed and and is selected
	//string str2 = "Add component (AND) new label bbbb ya basha: "; //ahmed
	//pIn->GetSrting(pOut, str2, "");   //ahmed 
	*/
//	}
	
}

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}

