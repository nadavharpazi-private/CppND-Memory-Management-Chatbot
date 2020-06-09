#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
	_chatBot = nullptr;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    if (_chatBot != nullptr) {
        delete _chatBot;
        _chatBot = nullptr;
    }

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(std::shared_ptr<GraphEdge> edge)
{
    _parentEdges.push_back(std::weak_ptr<GraphEdge>(edge));
}

void GraphNode::AddEdgeToChildNode(std::shared_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}