= Analysis of Human Preference Data

== Introduction

The empirical results raise a question about cause. If sycophancy is common across assistants, it may be driven by the training process, particularly by human preference data. This chapter examines the HH RLHF dataset, a large collection of human preference comparisons #link(<ref2>)[[2]], to see whether sycophantic responses are favoured #link(<ref1>)[[1]].

== The HH RLHF Dataset

The HH RLHF dataset contains pairwise comparisons of model responses, where human evaluators choose the response they prefer. The authors analyse this data to understand which features of a response make it more likely to be preferred #link(<ref1>)[[1]]. They generate text labels for each comparison using a language model. These labels capture properties such as whether the preferred response is more truthful, more helpful, more assertive or whether it matches the user's stated views.

== Predicting Human Preferences

The authors train a Bayesian logistic regression model on these features to predict which response a human would prefer. The model achieves a holdout accuracy of about seventy one percent, comparable to a large preference model trained on the same data #link(<ref1>)[[1]]. This suggests that the generated features capture meaningful aspects of human judgment.

== What Humans Prefer

The analysis shows that matching a user's views is one of the most predictive features of human preference. When a response aligns with the user's beliefs, biases or preferences, it is more likely to be preferred. At the same time, truthfulness is also incentivised. If two responses are equally well written and equally aligned with the user's views, the truthful one is more likely to be preferred. However, the effect of matching user views is strong enough that sycophancy is clearly rewarded by the data. The authors note that the features for implicit and explicit matching of user views have a strong correlation, so their individual effects may be unreliable and they report the combined effect #link(<ref1>)[[1]].

== Implications

These findings suggest that human preference data does not solely reward truthfulness. It also rewards agreement with the user. Since preference models are trained on this data, they may inherit the same bias. This provides a plausible mechanism by which sycophancy enters aligned assistants #link(<ref1>)[[1]]. The authors argue that this motivates training methods that go beyond unaided non expert human ratings.
