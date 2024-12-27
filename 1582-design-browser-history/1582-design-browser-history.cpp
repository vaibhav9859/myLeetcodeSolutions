class Node{
public:
    string data;
    Node* next;
    Node* prev;

    Node(string data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

class BrowserHistory {
public:
    Node* curPage;

    BrowserHistory(string homepage) {
        curPage = new Node(homepage);
    }
    
    void visit(string url) {
        if(curPage->next){
            delForwardHist(curPage->next);
        }

        curPage->next = new Node(url);
        curPage->next->prev = curPage;
        curPage = curPage->next;
    }

    void delForwardHist(Node* temp){
        while(temp and temp->next){
            temp = temp->next;
            delete temp->prev;
        }

        // if(temp) 
        delete temp;
    }
    
    string back(int steps) {
        while(curPage and curPage->prev and steps){
            curPage = curPage->prev;
            steps--;
        }

        return curPage->data;
    }
    
    string forward(int steps) {
        while(curPage and curPage->next and steps){
            curPage = curPage->next;
            steps--;
        }
        
        return curPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */