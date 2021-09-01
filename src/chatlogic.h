#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

/*
TASK 3

3.1 The GraphNodes in the vector _nodes are exclusively owned by the class ChatLogic.
	
In file chatlogic.h / chatlogic.cpp, the vector _nodes are adapted in a way that the 
instances of GraphNodes to which the vector elements refer are exclusively owned by the 
class ChatLogic. An appropriate type of smart pointer is used to achieve this.


3.2 GraphNode ownership is not transferred when passing instances.
	
When passing the GraphNode instances to functions, ownership is not transferred.

*/

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    //std::vector<GraphNode *> _nodes;
    //std::vector<GraphEdge *> _edges;

    std::vector<std::unique_ptr<GraphNode>> _nodes;
    //std::vector<std::unique_ptr<GraphEdgee>> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */