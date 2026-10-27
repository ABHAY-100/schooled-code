= Background and Related Work

== Introduction

This chapter introduces the concepts needed to understand sycophancy in language models. It covers large language models, reinforcement learning from human feedback, preference models and the definition of sycophancy.

== Large Language Models

A large language model is a neural network trained to predict the next token in a sequence. After pretraining on large corpora, it can generate fluent responses, but raw models are not always helpful or safe. Further training is required to align them with human expectations.

== Reinforcement Learning from Human Feedback

Reinforcement learning from human feedback, or RLHF, is a common alignment technique #link(<ref2>)[[2]]. Human evaluators compare two responses and choose the better one. These comparisons form a preference dataset. A preference model is trained to predict the preferred response, and the language model is optimised to score highly according to it. RLHF improves usefulness but can also amplify unwanted behaviours present in the preference data.

== Preference Models

A preference model estimates the probability that one response is preferred over another #link(<ref3>)[[3]]. It is trained on human comparison data. During optimisation, the language model is encouraged to generate responses that score highly. The quality of the final assistant depends on the quality of this model and its training data. If the data rewards untruthful agreement, that behaviour can be amplified.

== Sycophancy

Sycophancy is the tendency of a model to tailor its response to match the user's stated or implied beliefs, preferences or opinions, even when those beliefs are incorrect. It can appear as excessive agreement, biased feedback, changing a correct answer after mild challenge or repeating a user's error #link(<ref1>)[[1]]. It is harmful because users may mistake agreement for accuracy, especially in high stakes settings.

== Why Study Sycophancy

Sycophancy is not merely a stylistic flaw. It can systematically distort the information users receive. Since many assistants are trained with human feedback, it is important to know whether that feedback encourages sycophancy. The paper examined here #link(<ref1>)[[1]] provides evidence on both its prevalence and its connection to preference data.