#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class IGraph {

public:

    virtual ~IGraph() {}

    IGraph() {};

    IGraph(IGraph *_oth) {};

    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро

    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод
                                    // выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод
                                    // выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную

};
class ListGraph;
class MatrixGraph;

class ListGraph : public IGraph {
    std::vector<std::vector<int>> lists;
public:
    ListGraph(int vertices) {
        lists = std::vector<std::vector<int>>(vertices);
    }

    ListGraph(const ListGraph* other) {
        lists = other->lists;
    }

    ListGraph(const MatrixGraph* other);

    ListGraph(IGraph* other);

    void MatrixToList(const MatrixGraph* other);

    void AddEdge(int from, int to) override {
        lists[from].push_back(to);
    }

    int VerticesCount() const override {
        int count = 0;
        for (auto list : lists) {
            for (auto val : list) {
                count++;
            }
        }
        return count;
    }

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override {
        vertices = lists[vertex];
    }

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override {
        for (int i = 0; i < lists.size(); i++) {
             for (int j : lists[i]) {
                if (vertex == j) {
                    vertices.push_back(i);
                }
            }
        }
    }

    friend class MatrixGraph;
};

class MatrixGraph : public IGraph {
    std::vector<std::vector<bool>> matrix;
public:
    MatrixGraph(int vertices) {

        matrix = std::vector<std::vector<bool>>(vertices,std::vector<bool>(vertices, false));
    }
    MatrixGraph(const MatrixGraph* other) {
        matrix = other->matrix;
    }
    MatrixGraph(const ListGraph* other);

    MatrixGraph(IGraph* other);

    void ListToMatrix(const ListGraph* other);

    void AddEdge(int from, int to) override {
        matrix[from][to] = true;
    }

    int VerticesCount() const override {
        int count = 0;
        for (auto row : matrix) {
            for (auto val : row) {
                if (val) {
                    count++;
                }
            }
        }
        return count;
    }

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override {
        for (int col = 0; col < matrix[vertex].size(); col++) {
            if (matrix[vertex][col]) {
                vertices.push_back(col);
            }
        }
    }

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override {
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][vertex]) {
                vertices.push_back(row);
            }
        }
    }

    friend class ListGraph;

};

ListGraph::ListGraph(const MatrixGraph* other) {
    MatrixToList(other);
}

void ListGraph::MatrixToList(const MatrixGraph* other) {
    lists.clear();
    lists = std::vector<std::vector<int>>(other->matrix.size());
    for (int i = 0; i < other->matrix.size(); ++i) {
        for (int j = 0; j < other->matrix[i].size(); ++j) {
            if (other->matrix[i][j]) {
                lists[i].push_back(j);
            }
        }
    }
}

MatrixGraph::MatrixGraph(const ListGraph* other) {
    ListToMatrix(other);
}

void MatrixGraph::ListToMatrix(const ListGraph* other) {
    matrix.clear();
    matrix = std::vector<std::vector<bool>>(other->lists.size(),std::vector<bool>(other->lists.size(), false));
    for (int i = 0; i < other->lists.size(); ++i) {
        for (int val : other->lists[i]) {
            matrix[i][val] = true;
        }
    }
}

ListGraph::ListGraph(IGraph* other) {
    if (ListGraph* listGraph = dynamic_cast<ListGraph*>(other)){
        lists = listGraph->lists;
    } else if (MatrixGraph* matrixGraph = dynamic_cast<MatrixGraph*>(other)){
        MatrixToList(matrixGraph);
    }
}

MatrixGraph::MatrixGraph(IGraph* other) {
    if (MatrixGraph* matrixGraph = dynamic_cast<MatrixGraph*>(other)){
        matrix = matrixGraph->matrix;
    } else if (ListGraph* listGraph = dynamic_cast<ListGraph*>(other)){
        ListToMatrix(listGraph);
    }
}


std::string vectorToStr(std::vector<int> &vector) {

    std::string str;
    if (!vector.empty() ) {
        str = std::to_string(vector[0]);

        for (auto i = begin(vector) + 1; i != end(vector); ++i) {
            str +=  ", " + std::to_string(*i);
        }
    }
    return str;
}


int main() {
    std::cout << "Graph class implementation." << std::endl;
// ListGraph
    ListGraph* listGraph = new ListGraph(6);
    listGraph->AddEdge(0,1);
    listGraph->AddEdge(0,3);
    listGraph->AddEdge(1,2);
    listGraph->AddEdge(2,4);
    listGraph->AddEdge(2,5);
    listGraph->AddEdge(3,1);
    listGraph->AddEdge(3,4);
    listGraph->AddEdge(4,5);

    std::cout << "Enter vertex: " << std::endl;
    int vertex;
    std::cin >> vertex;

    std::string printNextVertices;
    std::string printPrevVertices;

    std::vector<int> nextVertices;
    listGraph->GetNextVertices(vertex,nextVertices);
    printNextVertices = vectorToStr(nextVertices);

    std::vector<int> prevVertices;
    listGraph->GetPrevVertices(vertex,prevVertices);
    printPrevVertices = vectorToStr(prevVertices);

    std::cout << "ListGraph: " << "\tCount Vertices: " << listGraph->VerticesCount()
              << "\tNextVertices for " << vertex << ": " << printNextVertices
              << "\tPrevVertices for " << vertex << ": " << printPrevVertices << std::endl;

// MatrixGraph


    MatrixGraph* matrixGraph = new MatrixGraph(6);

    matrixGraph->AddEdge(0,1);
    matrixGraph->AddEdge(0,3);
    matrixGraph->AddEdge(1,2);
    matrixGraph->AddEdge(2,4);
    matrixGraph->AddEdge(2,5);
    matrixGraph->AddEdge(3,1);
    matrixGraph->AddEdge(3,4);
    matrixGraph->AddEdge(4,5);

    nextVertices.resize(0);
    matrixGraph->GetNextVertices(vertex,nextVertices);
    printNextVertices = vectorToStr(nextVertices);

    prevVertices.resize(0);
    matrixGraph->GetPrevVertices(vertex,prevVertices);
    printPrevVertices = vectorToStr(prevVertices);

    std::cout << "MatrixGraph: " << "\tCount Vertices: " << matrixGraph->VerticesCount()
              << "\tNextVertices for " << vertex << ": " << printNextVertices
              << "\tPrevVertices for " << vertex << ": " << printPrevVertices << std::endl;

///

    ListGraph* listGraph2 = new ListGraph(listGraph);
    ListGraph* listGraph3 = new ListGraph(matrixGraph);
    MatrixGraph* matrixGraph2 = new MatrixGraph(matrixGraph);
    MatrixGraph* matrixGraph3 = new MatrixGraph(listGraph);

///

    IGraph* IGraph1 = new ListGraph(listGraph);
    IGraph* IGraph2 = new MatrixGraph(matrixGraph);

    ListGraph* listGraph4 = new ListGraph(IGraph1);
    ListGraph* listGraph5 = new ListGraph(IGraph2);
    MatrixGraph* matrixGraph4 = new MatrixGraph(IGraph1);
    MatrixGraph* matrixGraph5 = new MatrixGraph(IGraph2);

    delete listGraph;
    delete listGraph2;
    delete listGraph3;
    delete listGraph4;
    delete listGraph5;
    delete matrixGraph;
    delete matrixGraph2;
    delete matrixGraph3;
    delete matrixGraph4;
    delete matrixGraph5;
    delete IGraph1;
    delete IGraph2;

    return 0;
}

/*
Задача 2. Реализация класса графа


Что нужно сделать:
В любом доступном источнике прочитайте, что такое графы в дискретной математике и как граф можно представить в программе
 (что такое матрицы смежности и списки смежности)

Вам дан базовый интерфейс для представления ориентированного графа

Необходимо написать две реализаций интерфейса:

ListGraph, хранящий граф в виде массива списков смежности,
MatrixGraph, хранящий граф в виде матрицы смежности,
Также необходимо реализовать конструктор, принимающий IGraph*. Такой конструктор должен скопировать переданный граф в
 создаваемый объект (обратите внимание, что иногда в одну реализацию графа копируется другая) Реализуйте в том числе
 все конструкторы копий и операторы присваивания, если необходимо.



class IGraph {

public:

    virtual ~IGraph() {}

    IGraph() {};

    IGraph(IGraph *_oth) {};

    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро

    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную

};


Чек-лист для проверки задачи
Реализованы два класса-наследника, имплементирующие корректные алгоритмы работы с графом как с матрицей смежности и списками смежности

 */