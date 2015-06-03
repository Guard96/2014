//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	//устанавливаем первоначальный адрес в строке запроса
	MainForm->URL->Text = "http://www.1tv.ru/";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	if(MainForm->URL->Text != "")
        {
        	try
                {
        		//обращаемся по адресу, который указан в поле ввода
                	AnswerServer->Text = IdHTTP1->Get(URL->Text);
                	//получаем заголовки ответа от сервера
                	AnswerServer->Text = IdHTTP1->Response->RawHeaders->GetText();
                }
                //обрабатываем искдючения компонента Indy
                catch(EIdHTTPProtocolException &E)
                {
                	switch(E.ErrorCode)
                        {
                        	//обрабатываем коды ошибок
                        	case 400: ShowMessage("400 Cервер обнаружил в запросе клиента синтаксическую ошибку"); break;
                                case 401: ShowMessage("401 Запрос требует идентификации пользователя."); break;
                                case 404: ShowMessage("404 Страница не найдена"); break;
                                case 301: ShowMessage("301 Страница перемещена навсегда"); break;
                                case 302: ShowMessage("301 Страница временно перемещена"); break;

                                default : ShowMessage(String(E.ErrorCode)+" "+E.Message); break;
      				}
                	};
        	}

                //отключаемся от сервера
                IdHTTP1->Disconnect();
}
//---------------------------------------------------------------------------
