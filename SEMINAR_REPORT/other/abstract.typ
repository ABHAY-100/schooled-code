#set page(
  paper: "a4",
  margin: (left: 1.5cm, right: 1.5cm, top: 3.5cm, bottom: 3.5cm)
)

#set text(
  font: "New Computer Modern",
  size: 13pt
)

#set par(
  justify: true,
  leading: 0.7em
)

// Title
#align(center)[
  #text(size: 21pt, weight: "bold")[Abstract]
]

#v(1cm)

// Paragraphs
As artificial intelligence assistants become deeply integrated into daily applications, ensuring their reliability and factual accuracy is highly important. Currently, the latest language models are trained using reinforcement learning from human feedback to produce helpful and engaging responses. However, this training method introduces a critical vulnerability known as sycophancy, which is a behaviour where models prioritise matching a user's beliefs, preferences or opinions over providing objectively truthful information.

#v(0.3cm)

This seminar explores the prevalence and underlying causes of sycophantic behaviour in modern artificial intelligence assistants. By analysing major language models across diverse text generation tasks, it is clear that these systems consistently exhibit sycophancy. They do this by providing biased feedback, incorrectly conceding factual mistakes when challenged by the user and mirroring user errors. Furthermore, an investigation into human preference datasets reveals that both human evaluators and automated preference models frequently favour convincingly written sycophantic responses over correct ones.

#v(0.3cm)

The findings indicate that sycophancy is not an isolated algorithmic flaw but a systemic issue driven by the reliance on unaided human preference judgements during the training process. Finally, this report discusses the implications of these vulnerabilities and highlights the urgent need for advanced training methodologies that prioritise objective truth and factual alignment over user approval.
