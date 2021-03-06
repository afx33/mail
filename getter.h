#include "loader.h"
#include "trainer.h"

// get texts by url and create markov chain based on them
class Getter
{
public:
	Getter(const char *pipe_name, unsigned chain_rate);
	~Getter();

	// push content into markov chain
	// content is represented by url
	void get(const char *url);

	// save markov chain into file 
	void save(const char *filename);

	// load markov chain from file
	void load(const char *filename);

	// complete str with @words_cnt words count
	void complete(const char *str, unsigned words_cnt, std::string &out);
	
private:
	const char *m_pipe_name; // fifo filename
	int m_fd;		 // fifo file descriptor
	Loader m_loader;	 // downloader to get content by url
	Trainer m_trainer;	 // markov chain creator
};
