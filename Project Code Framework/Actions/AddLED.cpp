#include "AddLED.h"
#include "../ApplicationManager.h"

AddLED::AddLED(ApplicationManager *pApp):Action(pApp)
{
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED: Click to add the component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//check if within drawing area
	while (!(Cy > UI.ToolBarHeight +UI.GateBarHeight +  UI.AND2_Width / 2 && Cy < (UI.height - UI.StatusBarHeight) - UI.AND2_Width / 2))
	{
		pOut->PrintMsg("Please Add in the Drawing Area, try again...");
		pIn->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddLED::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Size
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	LED *pA=new LED(GInfo); 
	pManager->AddComponent(pA);
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}
