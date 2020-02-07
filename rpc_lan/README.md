# DS20RPC
First assignment for Distributed Systems Spring 2020
CSCI/ECEN 5673: Distributed Systems
Spring 2020
Programming Assignment 1
Due Date: 02/10/2020
The goal of this assignment is to implement clock synchronization in distributed
systems as well as gain experience with using ONC RPC and understand the overhead
RPC incurs.
Your task is to experiment with a client/server program in which a client sends a request
to a server and receives a reply from that server. The client records local clock times of
when the request was sent and when the corresponding reply was received, and also
learns the (server) clock times of when the server received that request and sent its
reply.
Implement two versions of this client/server program:
Version 1: Use UDP for communication. There are plenty of UDP client/server
programs available on the Internet. You may use one of these. Of course, make sure
that you understand the code and the code is working correctly before you use it.
Version 2: Use ONC RPC for communication. Again, there are plenty of RPC-based
programs available on the Internet. You may use one of these. Make sure that you
understand the code and the code is working correctly before you use it.
For each version, collect timing data for three different scenarios:
a) Client and server are running on the same machine
b) Client and server are running on different machines with in the CU-Boulder
campus
c) Client and server are running on different machines, one in CU campus and
the other at a different geographic location outside the CU campus,
preferably on a different continent
For each scenario, repeat your measurements every minute over a period of two hours.
Question 1: Compute roundtrip latencies along with average and standard deviation for
each scenario, and plot them in a graph. Provide an analysis of your results in terms of
why there is a variation in latencies, which ones you expect to be more accurate, etc.
Question 2: How much performance overhead does RPC incur under different
scenarios? Provide an explanation of this overhead. Your answer must be based on the
data you have collected.Question 3: Compute the offset (o i ) and delay (d i ) for each of the measurements for
each scenario using the NTP formula and plot them in a graph (x-axis: measurement #;
y-axis: o i or d i ). Provide an analysis of your results. What difference do you see in your
estimates between the two versions of your program? Based on your data, can you
justify the statement: The shorter and more symmetric the round-trip time is, the more
accurate the estimate of the current time.
Question 4: Compute server clock time estimate using the Cristian’s clock
synchronization algorithm, and plot the difference between the local clock and the
estimated server clock values for each scenario. Based on your observations, what is a
reasonable estimate of absolute minimum latency between the two machines you used
for experiments for different scenarios. Using this estimate, calculate the error bounds
for the synchronized time.
Submission and grading guidelines
1. Please submit a single zip file via the submission link provided on Moodle. Your
file must contain the following:
• All source code files including a makefile
• A README file that includes a description of how to compile and run your
program. In addition, include any limitations of your program – what works,
what doesn’t, sources of potential errors, etc.
• A PDF file that contains answers to the four questions.
• Raw measurement data for each scenario in separate files in some
reasonable format, e.g. Excel.
2. You may work in teams of size two students to write the programs and collect data.
However, you must answer the four questions individually. Include the name of
your team member in the code and writeup you submit.
3. We will conduct interview grading to grade your assignment. During your
interview, we will ask questions related to your code as well as your writeup. Each
interview will last for a maximum of 15 minutes.
4. Interview slots will be posted a few days before the submission deadline and will
close at the same time as the submission deadline. You are responsible for ensuring
that you do sign up for an interview slot and show up for your interview at your slot
time.
5. Inform us ahead of time if none of the posted interview slots work for you or if you
have to miss your interview after signing up for a slot due to some unavoidable
circumstances. If you do not sign up for an interview slot or do not show up for
interview at your signed-up slot, and haven’t contacted us beforehand, we reserve
the right to not grade your assignment or deduct some points from your grade.
