#include<iostream>
#include<cstdlib>
#include<SFML/Graphics.hpp>

using namespace std;
const int width = 1280;
const int height = 720;
const int n = 85;
int arr[85];
bool sorted;

sf::RenderWindow window(sf::VideoMode(width, height), "Sorting Algoritm Visualiser", sf::Style::Titlebar | sf::Style::Close );

void generatenewArray()
{
    sorted = false;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 650;
    }
}
void display_sorted()
{
    sorted = true;
    window.clear(sf::Color::Black);
    for (int i = 0; i < n; i++) 
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Green);
        window.draw(bar);
    }
    window.display();
}



void display_BubbleSort(int index1,int index2,int index3)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Bubble Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = index1; i < n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Blue);
        window.draw(bar);

    }
    for (int i = 0; i <index1; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index2)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else if (i == index3)
        {
            bar.setFillColor(sf::Color::Magenta);
        }
        else
        {
            bar.setFillColor(sf::Color::White);
        }
        window.draw(bar);
    }
    window.display();
}
void BubbleSort() {

    for (int i = 0; i < n -1; i++)
    {
        for (int j = 0; j < n -1- i; j++) {
            display_BubbleSort(n - i, j,j+1);
            if (arr[j] > arr[j + 1]) {
                display_BubbleSort(n - i, j,j+1);
                swap(arr[j], arr[j + 1]);
                display_BubbleSort(n - i, j + 1,j);
            }

        }
    }
}


void display_InsetionSort(int index1,int index2)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Insertion Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = 0; i <= index1; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index1)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else
        {
            bar.setFillColor(sf::Color::Blue);
        }
        window.draw(bar);
    }
    for (int i = index1+1; i < index2; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Blue);
        window.draw(bar);

    }
    for (int i = index2; i < n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::White);
        window.draw(bar);

    }
    
    window.display();
}



void insertionSort()
{
    int j = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int key = arr[i];
        j = i - 1;
        display_InsetionSort(i , i+1);
        while(j>=0 && key<arr[j])
        {
                arr[j + 1] = arr[j];
                arr[j] = key;
                display_InsetionSort(j, i + 1);
                j--;
        }
        arr[j + 1] = key;
        display_InsetionSort(j+1, i + 1);
    }
}


void display_SelectionSort(int index1, int index2,int min_idx)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Selection Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = 0; i <=index1; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Blue);
        window.draw(bar);
    }
    for (int i = index1+1; i <index2; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == min_idx)
        {
            bar.setFillColor(sf::Color::Magenta);
        }
        else {
            bar.setFillColor(sf::Color::White);
        }
        window.draw(bar);
    }
    for (int i = index2; i < n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index2)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else
        {
            bar.setFillColor(sf::Color::White);
        }
        window.draw(bar);
    }
    window.display();
}

void selectionSort()
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {


        min_idx = i;
        display_SelectionSort(i-1,i,min_idx);
        for (j = i + 1; j < n; j++) {
            display_SelectionSort(i-1,j,min_idx);
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            display_SelectionSort(i-1,min_idx,min_idx);
            swap(arr[min_idx], arr[i]);
        }
        display_SelectionSort(i - 1, i,min_idx);
    }
}




void display_MergeSort(int index,int si,int ei)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Merge Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = 0; i <=ei; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index && i!=si &&i!=ei)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else if (i == si)
        {
            bar.setFillColor(sf::Color::Yellow);
        }
        else if (i == ei)
        {
            bar.setFillColor(sf::Color::Magenta);
        }
        else
        {
            bar.setFillColor(sf::Color::Blue);
        }
        window.draw(bar);
    }
    for (int i = ei+1; i <n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }
    window.display();
  
}
void merge(int si, int mid, int ei)
{
    int len1 = mid - si + 1;
    int len2 = ei - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    int mainarrIndex = si;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[mainarrIndex++];
    }
    mainarrIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mainarrIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainarrIndex = si;

    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] < right[index2])
        {
            
            display_MergeSort(mainarrIndex,si,ei);
            arr[mainarrIndex++] = left[index1++];
        }
        else
        {
            
            display_MergeSort(mainarrIndex,si,ei);
            arr[mainarrIndex++] = right[index2++];
        }
    }
    while (index1 < len1)
    {
       
        display_MergeSort(mainarrIndex,si,ei);
        arr[mainarrIndex++] = left[index1++];
    }
    while (index2 < len2)
    {
        display_MergeSort(mainarrIndex,si,ei);
        arr[mainarrIndex++] = right[index2++];
    }
   
}


void mergeSort(int si, int ei)
{
    if (si < ei)
    {
        int mid = si + (ei - si) / 2;
        mergeSort(si, mid);
        mergeSort(mid + 1, ei);
        merge(si, mid, ei);
    }
}

void display_QuickSort(int index1,int index2, int low,int high)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Quick Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = 0; i < low; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Cyan);
        window.draw(bar);
    }
    for (int i = low; i <= high; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index1 && i!=high)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else if(i == index2 && i != high)
        {

            bar.setFillColor(sf::Color::Magenta);
        }
        else if (i == high)
        {
            bar.setFillColor(sf::Color::Yellow);
        }
        else
        {
            bar.setFillColor(sf::Color::Blue);
        }
        window.draw(bar);
    }
    for (int i = high + 1; i < n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }
    window.display();

}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        display_QuickSort(i,j,low,high);
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            display_QuickSort(i,j,low,high);

        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;
    return i;
}
void quickSort(int low, int high)
{
    if (low < high)
    {
        int pivot_idx = partition(low, high);
        quickSort(low, pivot_idx - 1);
        quickSort(pivot_idx + 1, high);
    }

}



void display_RadixSort(int index)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Radix Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = 0; i < index; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Cyan);
        window.draw(bar);
    }
    for (int i = index; i < n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else
        {
            bar.setFillColor(sf::Color::White);
        }
        window.draw(bar);
    }
    window.display();
}


void countSort(int pos)
{
    int count[10] = { 0 };
    for (int i = 0; i < n; i++)
    {
        ++count[((arr[i] / pos) % 10)];
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    int* temp = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        temp[--count[((arr[i] / pos) % 10)]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        display_RadixSort(i);
        arr[i] = temp[i];
    }
}
void radixSort()
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (int pos = 1; (max / pos) > 0; pos *= 10)
    {
        countSort(pos);
    }
}


void display_HeapSort(int index1,int index2,int index3)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Heap Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    for (int i = 0 ; i < index1; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        if (i == index2)
        {
            bar.setFillColor(sf::Color::Red);
        }
        else if (i == index3)
        {
            bar.setFillColor(sf::Color::Blue);
        }
        else
        {
            bar.setFillColor(sf::Color::White);
        }
        window.draw(bar);
        
    }
    for (int i = index1; i < n; i++)
    {
        sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
        bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
        bar.setFillColor(sf::Color::Cyan);
        window.draw(bar);
    }
    window.display();
}
void maxHeapify(int n,int i)
{
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if (l< n && arr[l] >arr[largest])
    {
        largest = l;
    }
    if (r< n && arr[r] >arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        display_HeapSort(n, i, largest);
        swap(arr[largest], arr[i]);
        display_HeapSort(n,i,largest);
        maxHeapify(n,largest);
    }
}
void heapSort()
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(n,i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(i,0);
    }
}



void display_ShellSort(int gap, int index1, int index2)
{
    window.clear(sf::Color::Black);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("D:\\San Dip\\SortVisualizer\\Font\\arial.ttf");
    text.setFont(font);
    text.setString("Shell Sort");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    window.draw(text);
    if (gap == 1)
    {
        for (int i = 0; i < index2; i++)
        {
            sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
            bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
            bar.setFillColor(sf::Color::Cyan);
            window.draw(bar);
        }
        for (int i = index2; i < n;i++)
        {
            sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
            bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
            if (i == index2)
            {
                bar.setFillColor(sf::Color::Red);
            }
            else
            {
                bar.setFillColor(sf::Color::White);
            }
            window.draw(bar);
        }
    }
    else {
        for (int i = 0; i < n; i++)
        {
            sf::RectangleShape bar(sf::Vector2f(12, arr[i]));
            bar.setPosition(sf::Vector2f(i * 15, height - arr[i]));
            if (i == index1)
            {
                bar.setFillColor(sf::Color::Red);
            }
            else if (i == index2)
            {
                bar.setFillColor(sf::Color::Blue);
            }
            else
            {
                bar.setFillColor(sf::Color::White);
            }
            window.draw(bar);

        }
    }
    window.display();
}

 void shell_Sort()
 {
     for (int gap = n / 2; gap >= 1;gap=gap/2)
     {
         for (int j = gap; j < n;j++)
         {
             for (int i = j - gap; i >= 0; i = i - gap)
             {
                 if(arr[i+gap]>arr[i])
                 {
                     break;
                 }
                 else{
                     if (gap == 1)
                     {
                         display_ShellSort(gap, i + gap, i);
                         swap(arr[i + gap], arr[i]);
                         display_ShellSort(gap, i + gap, i);
                     }
                     else {
                         display_ShellSort(gap,i + gap, i);
                         swap(arr[i + gap], arr[i]);
                         display_ShellSort(gap,i + gap, i);
                     }
                 }
             }
         }
     }
 }
int main() {
    
   while (window.isOpen())
    {
        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        if (sorted == false)
        {
             generatenewArray();
             BubbleSort();
             display_sorted();
             generatenewArray();
             insertionSort();
             display_sorted();
             generatenewArray();
             selectionSort();
             display_sorted();
             generatenewArray();
             mergeSort(0, n - 1);
             display_sorted();
             generatenewArray();
             quickSort(0, n - 1);
             display_sorted();
             generatenewArray();
             radixSort();
             display_sorted();
             generatenewArray();
             heapSort();
             display_sorted();
             generatenewArray();
             shell_Sort();
             display_sorted();
        }
    }
    return 0;
}




