#include "Connection.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, Component* pS, Component* pD, int Pin)
	:Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcCmpnt = pS;
	DstCmpnt = pD;
	PinNumber = Pin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

int Connection::GetPinNumber()
{
	return 0;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

void Connection::DrawFrame(Output* pOut)
{
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

Component* Connection::Copy()
{
	return NULL;
}

void Connection::Save(std::ofstream& stream)
{
	stream << SrcCmpnt->GetID() << " " << DstCmpnt->GetID() << " " << PinNumber << endl;
}

bool Connection::CanConnect()
{
	if (SrcPin && DstPin) {
		if (DstPin->getStatus() == STATUS::UNASSIGNED) {
			if (SrcPin->ConnectTo(this)) {
				DstPin->setStatus(LOW);
				return true;
			}
		}
	}
	return false;
}
