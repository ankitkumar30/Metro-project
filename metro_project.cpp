//////////////////// Bhopal Metro project  //////////////////////////

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a metro station
struct Station {
    string name;
    vector<pair<int, int>> connections; // {connected station index, distance}
};

// Class to represent the metro network
class Metro {
private:
    vector<Station> stations;

public:
    // Function to add a station to the network
    void addStation(const string& name) {
        stations.push_back({name, {}});
    }

    // Function to add a connection between two stations with a given distance
    void addConnection(int stationIndex1, int stationIndex2, int distance) {
        stations[stationIndex1].connections.push_back({stationIndex2, distance});
        stations[stationIndex2].connections.push_back({stationIndex1, distance});
    }

    // Function to find the shortest path using Dijkstra's algorithm
    vector<int> findShortestPath(int source, int destination);

    // Function to display the shortest path between stations
    void displayShortestPath(int source, int destination);
};

// Function to find the shortest path using Dijkstra's algorithm
vector<int> Metro::findShortestPath(int source, int destination) {
    vector<int> distance(stations.size(), INT_MAX);
    vector<int> parent(stations.size(), -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Declaring Min-Heap 

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& connection : stations[u].connections) {
            int v = connection.first;
            int w = connection.second;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    // Reconstruct the path
    vector<int> path;
    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
    return path;
}

 // Function to display the shortest path between stations
 void Metro::displayShortestPath(int source, int destination) {
    vector<int> shortestPath = findShortestPath(source, destination);

    // Print the result
    cout << "Shortest path from " << stations[source].name << " to " << stations[destination].name << ": "<<endl;
    
    for (int stationIndex : shortestPath) {
        cout <<"\u2193"<<stations[stationIndex].name <<endl;
    }
    cout << endl;
}

//Main function
int main() {
    // Create a metro network
    Metro metro;
    metro.addStation("Gandhi Nagar - Orange Line");
    metro.addStation("Karond - Orange Line");
    metro.addStation("Berasia - Orange Line");
    metro.addStation("Budhwara - Orange Line");
    metro.addStation("Jahangirabad - Orange Line");
    metro.addStation("Roushanpura");
    metro.addStation("Kotra Sultanabad - Orange Line");
    metro.addStation("Nehru Nagar - Orange Line");
    metro.addStation("Shyamla Hills - Orange Line");
    metro.addStation("Van Vihar - Green Line");
    metro.addStation("Jawahar Chowk - Green Line");
    metro.addStation("Rangmahal - Green Line");
    metro.addStation("Vidhan Sabha - Green Line");
    metro.addStation("MP Nagar - Green Line, Red Line");
    metro.addStation("6 no. stop - Green Line");
    metro.addStation("Shivaji Nagar - Green Line");
    metro.addStation("Char imli - Green Line");
    metro.addStation("Bittan Market - Green Line");
    metro.addStation("Shahpura - Green Line");
    metro.addStation("Gulmohar - Green Line");
    metro.addStation("Akriti Eco City - Green Line");
    metro.addStation("Saliya - Green Line");
    metro.addStation("Chandbad - Red Line");
    metro.addStation("Ashoka Garden - Red Line");
    metro.addStation("Govindpura - Red Line");
    metro.addStation("Minal - Red Line");
    metro.addStation("Piplani - Red Line");
    metro.addStation("Ayodhya Bypass - Red Line");
    metro.addStation("Anand Nagar - Red Line");
    metro.addStation("Awadhpuri - Red Line");
    metro.addStation("Barkheda Pathani - Red Line");
    metro.addStation("Saket Nagar - Red Line");
    metro.addStation("AIIMS - Red Line");
    metro.addStation("Barkatullah University - Red Line");
    metro.addStation("Misrod - Red Line");
    metro.addStation("Ratanpur - Red Line");
    metro.addStation("Bairagarh - Yellow Line");
    metro.addStation("Lalghati - Yellow Line");
    metro.addStation("Tajul Masjid - Yellow Line");
    metro.addStation("Hamidia Hospital - Yellow Line");
    metro.addStation("Kamla Park - Yellow Line");
    metro.addStation("Polytechnic Square - Yellow Line");
    metro.addStation("Roshanpura - Yellow Line, Orange Line");
    metro.addStation("New Market - Yellow Line, Green Line");
    metro.addStation("Mata Mandir - Yellow Line");
    metro.addStation("MANIT Square - Yellow Line");
    metro.addStation("Patrakar Colony - Yellow Line");
    metro.addStation("Chuna Bhatti - Yellow Line");
    metro.addStation("Sarvdharm - Yellow Line");
    metro.addStation("Bima Kunj - Yellow Line");
    metro.addStation("Danish Kunj - Yellow Line");
    metro.addStation("Nayapura - Yellow Line");
    metro.addStation("Bairagarh Chichli - Yellow Line, Green Line");
    
    metro.addConnection(0, 1, 5); // Connection between Station A and Station B with distance 5
    metro.addConnection(1, 2, 3); // Connection between Station B and Station C with distance 3
    metro.addConnection(2, 3, 6);
    metro.addConnection(3, 4, 8);
    metro.addConnection(4, 42, 18);
    metro.addConnection(42, 43, 6);
    metro.addConnection(42, 41, 6);//
    metro.addConnection(42, 6, 24);
    metro.addConnection(6, 7, 4);
    metro.addConnection(7, 8, 8);
    metro.addConnection(40, 41, 6);
    metro.addConnection(39, 40, 3);
    metro.addConnection(38, 39, 3);
    metro.addConnection(37, 38, 4);
    metro.addConnection(36, 37, 4);
    metro.addConnection(43, 11, 5);
    metro.addConnection(10, 11, 3);
    metro.addConnection(9, 10, 7);
    metro.addConnection(43, 12, 12);
    metro.addConnection(12, 13, 8);
    metro.addConnection(43, 44, 3);
    metro.addConnection(44, 45, 6);
    metro.addConnection(45, 46, 4);
    metro.addConnection(46, 47, 4);
    metro.addConnection(47, 48, 6);
    metro.addConnection(48, 49, 6);
    metro.addConnection(49, 50, 6);
    metro.addConnection(50, 51, 6);
    metro.addConnection(51, 52, 3);
    metro.addConnection(52, 21, 7);
    metro.addConnection(20, 21, 3);
    metro.addConnection(19, 20, 3);
    metro.addConnection(18, 19, 2);
    metro.addConnection(17, 18, 4);
    metro.addConnection(16, 17, 3);
    metro.addConnection(15, 16, 3);
    metro.addConnection(14, 15, 3);
    metro.addConnection(14, 13, 5);
    metro.addConnection(13, 23, 7);
    metro.addConnection(22, 23, 3);
    metro.addConnection(13, 24, 6);
    metro.addConnection(24, 25, 3);
    metro.addConnection(25, 26, 2);
    metro.addConnection(26, 27, 2);
    metro.addConnection(27, 28, 3);
    metro.addConnection(28, 29, 5);
    metro.addConnection(29, 30, 4);
    metro.addConnection(30, 31, 5);
    metro.addConnection(31, 32, 4);
    metro.addConnection(32, 33, 3);
    metro.addConnection(33, 34, 3);
    metro.addConnection(34, 35, 3);
   
    
    unordered_map<string,int> mpp;
    mpp["Gandhi Nagar"] = 0;
    mpp["Karond"] = 1;
    mpp["Berasia"] = 2;
    mpp["Budhwara"] = 3;
    mpp["Jahangirabad"] = 4;
    mpp["Roushanpura"] = 5;
    mpp["Kotra Sultanabad"] = 6;
    mpp["Nehru Nagar"] = 7;
    mpp["Shyamla Hills"] = 8;
    mpp["Van Vihar"] = 9;
    mpp["Jawahar Chowk" ] = 10;
    mpp["Rangmahal"] = 11;
    mpp["Vidhan Sabha"] = 12;
    mpp["MP Nagar"] = 13;
    mpp["6 no. stop"] = 14;
    mpp["Shivaji Nagar"] = 15;
    mpp["Char imli"] = 16;
    mpp["Bittan Market"] = 17;
    mpp["Shahpura"] = 18;
    mpp["Gulmohar"] = 19;
    mpp["Akriti Eco City"] = 20;
    mpp["Saliya"] = 21;
    mpp["Chandbad"] = 22;
    mpp["Ashoka Garden"] = 23;
    mpp["Govindpura"] = 24;
    mpp["Minal"] = 25;
    mpp["Piplani"] = 26;
    mpp["Ayodhya Bypass"] = 27;
    mpp["Anand Nagar"] = 28;
    mpp["Awadhpuri"] = 29;
    mpp["Barkheda Pathani"] = 30;
    mpp["Saket Nagar"] = 31;
    mpp["AIIMS"] = 32;
    mpp["Barkatullah University"] = 33;
    mpp["Misrod"] = 34;
    mpp["Ratanpur"] = 35;
    mpp["Bairagarh"]= 36;
    mpp["Lalghati"] = 37;
    mpp["Tajul Masjid"] = 38;
    mpp["Hamidia Hospital"] = 39;
    mpp["Kamla Park"] = 40;
    mpp["Polytechnic Square"] = 41;
    mpp["Roshanpura"] = 42;
    mpp["New Market"] = 43;
    mpp["Mata MAndir"] = 44;
    mpp["MANIT Square"] = 45;
    mpp["Patrakar Colony"] = 46;
    mpp["Chuna Bhatti"] = 47;
    mpp["Sarvdharm"] = 48;
    mpp["Bima Kunj"] = 49;
    mpp["Danish Kunj"] = 50;
    mpp["Nayapura"] = 51;
    mpp["Bairagarh Chichli"] = 52;

    // Example: Find the shortest path from Station A to Station B
    string source ; // Station A
    cout<<"Enter Source Station:"<<endl;
    fflush(stdin);
    getline(cin,source);
  
    
    string destination; // Station B
    cout<<"Enter destination Station:"<<endl;
    fflush(stdin);
    getline(cin,destination);
    metro.displayShortestPath(mpp[source], mpp[destination]);
    return 0;
}
