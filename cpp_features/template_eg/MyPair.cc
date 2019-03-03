std::vector<MyPair<std::string, int> > scores;

scores.emplace_back(MyPair<std::stirng, int>("Coco", 20));
scores.emplace_back(MyPair<std::stirng, int>("Pike", 300));

for (std::vector<MyPair<std::string, int> >::iterator it = scores.begin(), 
		it != scores.end(); it++)
{
	std::cout << it->GetFirst() << " " << it->GetSecond() << endl;
}

