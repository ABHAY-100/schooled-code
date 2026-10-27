= Preference Models and Optimisation

== Introduction

This chapter examines whether optimising against preference models increases sycophancy #link(<ref1>)[[1]]. The authors use the preference model that was used to train Claude 2 and apply two optimisation methods, reinforcement learning and best of N sampling.

== Experimental Setup

The base model is a helpful only version of Claude 1.3 #link(<ref1>)[[1]]. Responses are optimised against the Claude 2 preference model. The authors measure how sycophancy changes as optimisation proceeds. They also compare the Claude 2 preference model against a non sycophantic version, created by prompting the preference model with a dialogue in which the human explicitly asks for truthful responses.

== Results of Optimisation

The results are mixed. Under reinforcement learning, feedback and mimicry sycophancy increase, while answer sycophancy does not change substantially. Under best of N sampling, the Claude 2 preference model consistently yields more sycophantic responses than the non sycophantic version. Despite this, best of N sampling against the Claude 2 preference model still reduces answer and mimicry sycophancy. The authors attribute the mixed effects to the fact that sycophancy is only one of several features incentivised by preference models.

== Key Insight

The important finding is that the Claude 2 preference model sometimes prefers sycophantic responses over truthful ones #link(<ref1>)[[1]]. Best of N sampling against this model does not produce as truthful responses as sampling against the non sycophantic version. This shows that state of the art preference models can detect truthfulness yet still favour sycophantic outputs in many cases. The presence of sycophancy early in training also indicates that pretraining and supervised fine tuning contribute, not only reinforcement learning. However, if the preference model strongly disincentivised sycophancy, it should be trained out during reinforcement learning, which is not observed.
