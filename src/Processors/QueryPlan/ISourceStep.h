#pragma once
#include <Processors/QueryPlan/IQueryPlanStep.h>

namespace DB
{

/// Step which takes empty pipeline and initializes it. Returns single logical DataStream.
class ISourceStep : public IQueryPlanStep
{
public:
    explicit ISourceStep(DataStream output_stream_);

    QueryPipelinePtr updatePipeline(QueryPipelines pipelines) override;

    virtual void initializePipeline(QueryPipeline & pipeline) = 0;

    void describePipeline(FormatSettings & settings) const override;

protected:
    /// We collect processors got after pipeline transformation.
    Processors processors;
};

}
