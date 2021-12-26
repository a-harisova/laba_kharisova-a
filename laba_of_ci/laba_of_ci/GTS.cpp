#include "GTS.h"

using namespace std;

void GTS::InputPipe()
{
	PIPE pipe;
	cin >> pipe;
	pipes.emplace(pipe.MaxID, pipe);
}

void GTS::InputKS()
{
	KS ks;
	cin >> ks;
	kss.emplace(ks.MaxID, ks);
}

void GTS::PrintAllPipes()
{
	if (pipes.size() != 0)
	{
		for (const auto& [id, p] : pipes)
		{
			cout << id;
			cout << p << endl;
		}
	}
	else
		cout << "No pipe data, please enter it and try again." << endl;
}

void GTS::PrintAllKSs()
{
	if (kss.size() != 0)
	{
		for (const auto& [id, k] : kss)
		{
			cout << id;
			cout << k << endl;
		}
	}
	else
		cout << "No ks data, please enter it and try again." << endl;
}

void GTS::EditPipes()
{
	if (pipes.size() != 0)
	{
		cout << "Do you want to edit all pipes or multiple? Please, enter 1 if all pipes or 2 if multiple pipe: ";
		switch (Get_Correct_Number(1, 2))
		{
		case 1:
		{
			for (auto& [id, p] : pipes)
				p.Edit_Pipe();
			break;
		}
		case 2:
		{
			cout << "How many pipes do you want to edit? Please, enter integer value of pipes (1, " << pipes.size() << "):";
			int n = Get_Correct_Number(1u, pipes.size());
			for (int i = 0; i < n; i++)
			{
				cout << "Please enter index (1, " << pipes.size() << "): ";
				unsigned int index = Get_Correct_Number(1u, pipes.size());
				pipes[index].Edit_Pipe();
			}
			break;
		}
		}
	}
	else
		cout << "No pipe data, please enter it and try again." << endl;
}

void GTS::EditKSs()
{
	if (kss.size() != 0)
	{
		cout << "Do you want to edit all kss or multiple? Please, enter 1 if all kss or 2 if multiple ks: ";
		switch (Get_Correct_Number(1, 2))
		{
		case 1:
		{
			for (auto& [id, k] : kss)
				k.Edit_KS();
			break;
		}
		case 2:
		{
			cout << "How many kss do you want to edit? Please, enter integer value of kss (1, " << kss.size() << "):";
			int n = Get_Correct_Number(1u, kss.size());
			for (int i = 0; i < n; i++)
			{
				cout << "Please enter index (1, " << kss.size() << "): ";
				unsigned int index = Get_Correct_Number(1u, kss.size());
				kss[index].Edit_KS();
			}
			break;
		}
		}
	}
	else
		cout << "No ks data, please enter it and try again." << endl;
}

void GTS::Save(const string& filename)
{
	ofstream fout;
	fout.open(filename);
	if (fout.is_open())
	{
		fout << pipes.size() << endl;
		fout << kss.size() << endl;
		for (const auto& [id, p] : pipes)
			fout << p;
		for (const auto& [id, k] : kss)
			fout << k;
		fout.close();
	}
	else
		cout << "Error! Text file didn't open! Try again." << endl;
}

void GTS::Dowload(string filename)
{
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		PIPE pipe;
		KS ks;
		int kol = 0;
		int pipes_size, kss_size;
		fin >> pipes_size >> kss_size;
		for (int i = 1; i <= pipes_size; i++)
		{
			fin >> pipe;
			for (auto& [id, p] : pipes)
			{
				if (pipe.GetID() == id)
				{
					kol++;
				}
			}
			if (kol == 0)
			{
				pipe.MaxID++;
				pipes.emplace(pipe.MaxID, pipe);
			}
			else
			{
				kol = 0;
			}
		}
		for (int i = 1; i <= kss_size; i++)
		{
			fin >> ks;
			for (auto& [id, k] : kss)
			{
				if (ks.GetID() == id)
				{
					kol++;
				}
			}
			if (kol == 0)
			{
				ks.MaxID++;
				kss.emplace(ks.MaxID, ks);
			}
			else
			{
				kol = 0;
			}
		}
		fin.close();
	}
	else
		cout << "File didn't open! Please, try again.";
}

void GTS::Filter_For_PIPE()
{
	PipeFilter(pipes);
}

void GTS::Filter_For_KS()
{
	KSFilter(kss);
}

void GTS::DeletePipe()
{
	if (pipes.size())
	{
		cout << "Please, enter the index(1 - " << pipes.size() << "): ";
		int index = Get_Correct_Number(1u, pipes.size());
		pipes.erase(index);
	}
	else
		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
}

void GTS::DeleteKS()
{
	if (kss.size())
	{
		cout << "Please, enter the index(1 - " << kss.size() << "): ";
		int index = Get_Correct_Number(1u, kss.size());
		kss.erase(index);
	}
	else
		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
}

vector <vector <int>> GTS::AddGraph()
{
	unordered_map <int, int> VerticesIndex = IndexVertices();
	vector <vector <int>> ribs;
	ribs.resize(VerticesIndex.size());
	for (const auto& [i, p] : pipes)
		if (p.CanBeUsed())
			ribs[VerticesIndex[p.out]].push_back(VerticesIndex[p.in]);
	return ribs;
}

unordered_map <int, int> GTS::IndexVertices()
{
	set <int> vertices;
	for (const auto& [i, p] : pipes)
		if (p.CanBeUsed() && kss.count(p.in) && kss.count(p.out)) 
		{
			vertices.insert(p.out);
			vertices.insert(p.in);
		}
	unordered_map <int, int> VerticesIndex;
	int i = 0;
	for (const int& v : vertices)
		VerticesIndex.insert({ v, i++ });
	return VerticesIndex;
}

unordered_map <int, int> GTS::IndexVerticesBack()
{
	set <int> vertices;
	for (const auto& [i, p] : pipes)
		if (p.CanBeUsed() && kss.count(p.in) && kss.count(p.out)) 
		{
			vertices.insert(p.out);
			vertices.insert(p.in);
		}
	unordered_map <int, int> VerticesIndex;
	int i = 0;
	for (const int& v : vertices)
		VerticesIndex.insert({ i++, v });
	return VerticesIndex;
}

void DepthFirstSearch(int v, vector <char>& cl, vector <int>& p, int& start, const vector <vector <int>>& ribs, vector <int>& result)
{
	cl[v] = 1;
	for (size_t i = 0; i < ribs[v].size(); ++i) 
	{
		int to = ribs[v][i];
		if (cl[to] == 0) 
		{
			p[to] = v;
			DepthFirstSearch(to, cl, p, start, ribs, result);
		}
		else if (cl[to] == 1) 
		{
			start = to;
			return;
		}
	}
	result.push_back(v);
	cl[v] = 2;
}

void GTS::TopologicalSort(const unordered_map <int, int>& VerticesIndex)
{
	int n = ribs.size();
	vector <int> result;
	vector <char> cl;
	vector <int> p;
	int cycle_start;
	p.assign(n, -1);
	cl.assign(n, 0);
	cycle_start = -1;
	result.clear();
	for (int i = 0; i < n; ++i)
		if (cl[i] != 2)
			DepthFirstSearch(i, cl, p, cycle_start, ribs, result);
	if (cycle_start == -1) {
		reverse(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) 
		{
			cout << " KS's index: " << VerticesIndex.at(result[i]) << " --> ";
		}
		cout << endl;
	}
	else
		cout << "Sorting cannot be applied to a graph containing a cycle " << endl;
}

void GTS::ConnectPipeAndKSs()
{
	if (pipes.size() > 0 && kss.size() > 1)
	{
		cout << "Please, enter the index of pipe you want to connect: ";
		int pipeId = Get_Correct_Number(1u, pipes.size());
		cout << "Please, enter the index of ks where the pipe enters: ";
		int in = Get_Correct_Number(1u, kss.size());
		cout << "Please, enter the index of ks where the pipe comes out: ";
		int out = Get_Correct_Number(1u, kss.size());
		if (pipes[pipeId].in == 0 && pipes[pipeId].out == 0 && out != in) 
		{
			pipes[pipeId].Connect(in, out);
		}
		else
			cout << "Error! Please try again!" << endl;
	}
	else
		cout << "Error! No objects to connect! Please try again! " << endl;
}

void GTS::DisconnectPipeAndKSs()
{
	if (pipes.size() > 0 && kss.size() > 1)
	{
		ShowConnection();
		cout << "Please, enter the index of pipe you want to disconnect: " << endl;
		int pipeId = Get_Correct_Number(1u, pipes.size());
		if (pipes[pipeId].Connection()) {
			pipes[pipeId].BreakTheConnection();
		}
		else
			cout << "Error! No objects to disconnect! Please try again!" << endl;
	}
	else
		cout << "Error! No objects to disconnect! Please try again!" << endl;
}

void GTS::ShowConnection()
{
	if (pipes.size() > 0 && kss.size() > 1) 
	{
		for (auto& [id, p] : pipes)
			if (p.Connection())
				p.ShowTheConnection(id);
			else cout << "Pipe " << id << " hasn't connection" << endl;
	}
	else cout << "Error! No connection! Please try again!" << endl;
}

void GTS::Sort()
{
	if (pipes.size() > 0 && kss.size() > 1) 
	{
		ribs = AddGraph();
		if (ribs.size() == 0)
		{
			cout << "Error! No connected objects! Please try again!" << endl;
		}
		else
		{
			cout << "What do you want to do?" << endl
				<< "Enter 1 if you want to do topological sort. " << endl
				<< "Enter 2 if you want to find max stream. " << endl
				<< "Enter 3 if you want to find the shortest way. " << endl
				<< "Enter 0 if you want to exit." << endl;
			switch (Get_Correct_Number(0, 3))
			{
				case 1:
				{
					unordered_map <int, int> VerticesIndex = IndexVerticesBack();
					TopologicalSort(VerticesIndex);
					break;
				}
				case 2:
				{
					MaxStream();
					break;
				}
				case 3:
				{
					unordered_map <int, int> VerticesIndex = IndexVerticesBack();
					ShortestWay(VerticesIndex);
					break;
				}
				case 0:
				{
					break;
				}
				default:
				{
					cout << "Error! Please try again!" << endl;
					break;
				}
			}
		}
	}
	else cout << "Error! No connected objects! Please try again!" << endl;
}

vector <vector <double>> GTS::MatrixWeights() 
{
	vector <vector <double>> weights;
	unordered_map <int, int> VerticesIndex = IndexVertices();
	weights.assign(VerticesIndex.size(), {});
	for (int i = 1; i < VerticesIndex.size(); i++) 
	{
		weights[i].assign(VerticesIndex.size(), INT_MAX);
		weights[i][i] = 0;
	}
	for (const auto& [i, p] : pipes)
		if (p.CanBeUsed())
			weights[VerticesIndex[p.out]][VerticesIndex[p.in]] = p.length;
	return weights;
}

vector <vector <int>> GTS::MatrixThroughput() 
{
	vector <vector <int>> thro;
	unordered_map <int, int> VerticesIndex = IndexVertices();
	thro.assign(VerticesIndex.size(), {});
	for (int i = 1; i < VerticesIndex.size(); i++)
		thro[i].assign(VerticesIndex.size(), 0);
	for (const auto& [i, p] : pipes)
		if (p.CanBeUsed())
			thro[VerticesIndex[p.out]][VerticesIndex[p.in]] = p.performance;
	return thro;
}

void GTS::MaxStream()
{
	int start, end;
	cout << "Please enter index of KS from which to start the search for the maximum stream: ";
	start = Get_Correct_Number(1u, kss.size());
	cout << "Please enter index of KS from which to end the search for the maximum stream: ";
	end = Get_Correct_Number(1u, kss.size());
	int n = throughput.size();
	vector <vector <int>> thr = throughput;
	double MaxStream = 0;
	while (true) 
	{ 
		vector <int> parent (n, -1);
		vector <bool> used (n, true);
		queue <int> q;
		used[start] = false;
		q.push(start);
		while (!q.empty()) 
		{
			int v = q.front();
			q.pop();
			for (int i = 0; i < n; i++) 
			{
				if (!used[i] && thr[v][i] > 0) 
				{
					parent[i] = v;
					used[i] = true;
					q.push(i);
				}
			}
		}
		if (!used[end])
			break;
		int DopStream = INT_MAX;
		int ptr = end;
		while (ptr != start) 
		{
			DopStream = min(DopStream, thr[parent[ptr]][ptr]);
			ptr = parent[ptr];
		}
		ptr = end;
		while (ptr != start) 
		{
			thr[parent[ptr]][ptr] -= DopStream;
			thr[ptr][parent[ptr]] += DopStream;
			ptr = parent[ptr];
		}
		MaxStream += DopStream;
	}
	cout << "Maz stream = " << MaxStream << endl;
}

void GTS::ShortestWay(const unordered_map<int, int>& IndexVerticesBack)
{
	int start, end;
	cout << "Please enter index of KS from which to start the search for the shortest way: ";
	start = Get_Correct_Number(1u, kss.size());
	cout << "Please enter index of KS from which to end the search for the shortest way: ";
	end = Get_Correct_Number(1u, kss.size());
	vector <vector <double>> w = weight;
	int n = w.size();
	vector <vector <int>> restore;
	restore.resize(n);
	for (int i = 0; i < n; i++)
		for (int t = 0; t < n; t++)
			restore[i].push_back(t);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (w[i][j] > w[i][k] + w[k][j]) 
				{
					w[i][j] = w[i][k] + w[k][j];
					restore[i][j] = restore[i][k];
				}
	if (w[start][end] == INT_MAX) 
	{
		cout << "There is no way" << endl;
		return;
	}
	cout << "Way from KS " << start << " to the KS " << end << " = " << w[start][end] << endl << "This way is: " << endl;
	int temp = start;
	while (temp != end) {
		cout << IndexVerticesBack.at(temp) << " -> ";
		temp = restore[temp][end];
	}
	cout << IndexVerticesBack.at(end) << endl;
}