---
header-includes:
  - \usepackage[ruled,vlined,linesnumbered]{algorithm2e}
---

## The Bellman-Ford algorithm ##
The Bellman-Ford algorithm solves single-source shortest-paths problem, when the weight of edge could be negative. It return false if there is negative weighted cycle, and return true, minimum single-sourse paths if otherwise. 

# Algorithm 1
\begin{algorithm}[H]
  \KwData{this text}
  \KwResult{how to write algorithm with \LaTeX2e }
  initialization\;
  \While{not at end of this document}{
    read current\;
    \eIf{understand}{
      go to next section\;
      current section becomes this one\;
    }{
      go back to the beginning of current section\;
    }
  }
  \caption{How to write algorithms}
\end{algorithm}
