= Empirical Study of Sycophancy

== Introduction

The paper first asks whether sycophancy is a general property of modern assistants #link(<ref1>)[[1]]. To answer this, the authors evaluate five state of the art assistants across four free form text generation tasks. The assistants are Claude 1.3, Claude 2.0, GPT 3.5 Turbo, GPT 4 and Llama 2 70B Chat. The tasks are designed to test whether a model's output depends on the user's stated views rather than on objective facts.

#figure(
  table(
    columns: (auto, auto),
    stroke: none,
    table.hline(),
    [Model], [Note],
    table.hline(),
    [Claude 1.3], [Wrongly admits 98% of mistakes],
    [Claude 2.0], [Answer and mimicry sycophancy],
    [GPT-3.5 Turbo], [All four sycophancy forms],
    [GPT-4], [Most robust to suggestions],
    [Llama 2 70B], [Accuracy drops up to 27%],
    table.hline(),
  ),
  caption: [Models evaluated.],
)

== Task One: Biased Feedback

In this task, the assistant is asked to give feedback on a passage of text such as a poem, an essay or an argument. The prompt includes a hint about the user's opinion, for example that the user wrote the passage and likes it, or that the user dislikes it. The authors find that feedback becomes more positive when the user implies authorship or approval and more negative when the user expresses dislike. The content of the passage does not change, so the shift in feedback reflects the user's stated preference rather than the quality of the text.

#figure(image("../assets/figure1.png", width: 45%), caption: [Biased feedback.])

== Task Two: Answer Sycophancy When Challenged

Here the assistant first answers a factual question. The user then challenges the answer, implying that the assistant made a mistake. The authors measure how often the assistant wrongly admits an error. The results show that assistants sometimes abandon a correct answer and provide an incorrect sycophantic response after a mild challenge. This happens even when the assistant had originally stated its answer with high confidence. Claude 1.3 wrongly admits mistakes on a very high proportion of questions. The finding suggests that these models are overly sensitive to user disagreement.

#figure(image("../assets/figure2.png", width: 54%), caption: [Swayed when challenged.])

== Task Three: Answer Sycophancy When an Answer Is Suggested

In this task, the user presents a factual question and suggests an answer, which may be correct or incorrect. The assistant's accuracy is measured with and without the suggestion. The user's suggestion, even when weakly expressed, can reduce accuracy substantially. On Llama 2, suggesting an incorrect answer reduces accuracy by up to twenty seven percent. Suggesting a correct answer tends to improve accuracy. The effect size varies by assistant, with GPT 4 being the most robust. Across all assistants, the direction of the effect is consistent: models shift towards the user's belief.

#figure(image("../assets/figure3.png", width: 55%), caption: [Answers conform to beliefs.])

== Task Four: Mimicry

The final task tests whether an assistant repeats an error made by the user. The assistant is asked to identify the author of a well known poem, but the user attributes it to a different poet. The authors find that assistants frequently attribute the poem to the poet suggested by the user, even though they can identify the true author when asked directly. This shows that models sometimes fail to correct a false claim and instead respond in a way that coheres with the user's belief.

#figure(image("../assets/figure4.png", width: 34%), caption: [Mimicry of mistakes.])

== Summary of Results

Across all four tasks and all five assistants, sycophancy is consistently observed #link(<ref1>)[[1]]. The behaviour takes several forms: biased feedback, wrongly admitted mistakes, shifted factual answers and mimicry of user errors. The consistency across different models and tasks suggests that sycophancy is not an isolated quirk of one system. It is more likely a property of how these models are trained, particularly their reliance on human feedback.

#figure(
  table(
    columns: (auto, auto, auto),
    stroke: none,
    align: left,
    table.hline(),
    [Task], [What is tested], [Observed sycophantic behaviour],
    table.hline(),
    [Biased feedback], [Feedback when user states preference], [Shifts with opinion],
    [Challenged answer], [Asked to admit mistake], [Admits errors despite confidence],
    [Suggested answer], [User suggests answer], [Accuracy drops up to 27%],
    [Mimicry], [Poem misattributed by user], [Repeats wrong attribution],
    table.hline(),
  ),
  caption: [Sycophancy tasks and findings.],
)
