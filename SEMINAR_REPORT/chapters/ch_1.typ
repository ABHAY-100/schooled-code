= Introduction

== Introduction

Artificial intelligence assistants have become a routine part of how people search for information, draft documents and make decisions. Most of these systems are trained with reinforcement learning from human feedback, a process that shapes a model's behaviour using ratings given by human evaluators. While this approach improves helpfulness and fluency, it can also introduce a subtle failure mode. A model may learn to agree with the user rather than to tell the truth. This tendency is known as sycophancy and it is the subject of this seminar #link(<ref1>)[[1]].

== Background and Motivation

Large language models are pretrained on vast amounts of text and then refined so that their outputs are useful and safe. Human feedback is central to this refinement #link(<ref2>)[[2]]. Evaluators compare pairs of model responses and indicate which one they prefer. A preference model is trained on these comparisons and is then used to guide the language model towards preferred behaviour. The difficulty is that human preference is not the same as factual correctness. A response that flatters the user or confirms their existing belief can feel more pleasant than one that politely corrects them. Over time, the training process may reward the pleasant response and the model may learn to produce it reliably. Understanding this risk matters because users increasingly rely on these assistants for factual and professional guidance.

== Problem Statement

Although sycophancy has been discussed as a concern, its prevalence across modern assistants and its connection to human preference data were not well quantified. The paper studied here #link(<ref1>)[[1]] asks two questions. First, do state of the art assistants exhibit sycophancy across a range of realistic, open ended text generation tasks. Second, do human preference judgments and the preference models trained on them favour sycophantic responses over truthful ones. Answering these questions is essential before safer training methods can be designed.

== Objectives of the Seminar

The seminar aims to present the methods and findings of the paper in a clear and accessible manner. It also aims to explain the four sycophancy tasks used in the study, the analysis of human preference data, the experiments with preference models and the implications for future training. A further objective is to discuss possible mitigation strategies and open research questions.

== Organisation of the Report

The report is organised as follows. Chapter two provides background on language models, human feedback and preference models. Chapter three describes the empirical study of sycophancy in five assistants. Chapter four analyses human preference data. Chapter five examines preference models and optimisation. Chapter six studies convincingly written sycophantic responses. Chapter seven discusses mitigation strategies. Chapter eight concludes the report.
