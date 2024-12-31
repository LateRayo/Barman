///*
// * CALLBACK.cpp
// *
// *  Created on: 23 ago. 2023
// *      Author: gusta
// */
//


#include "Defines.h"

std::vector<CALLBACK*> vCallBack;

void CALLBACK::Callback( void )
{
	// Hay que crearla vacia, es la que luego se carga en la herencia
}

CALLBACK::CALLBACK()
{
	vCallBack.push_back( this );
}

void CALLBACK::SysTickCall( void )
{
	for (CALLBACK* q : vCallBack )
		q->Callback();
}

//#include "Defines.h"
//
//extern std::vector<CALLBACK*> vCallBack;
//
//void CALLBACK::Callback(void)
//{
//	if ( callback )
//		callback();
//}
//
//CALLBACK::CALLBACK( )
//{
//	Set(nullptr);
//}
//
//CALLBACK::CALLBACK( void (*CallBack) (void) )
//{
//	Set(CallBack);
//}
//
//void CALLBACK::Set( void (*CallBack) (void) )
//{
//	callback = CallBack;
//
//	if ( callback )
//		vCallBack.push_back( this );
//}
