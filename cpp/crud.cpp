/////////////////////////////////////////////////////////////////////
/// find
/////////////////////////////////////////////////////////////////////
 
    // Coersion from document::view into model::find
    auto cursor = coll.find(doc_view);
  
    // Explicit creation of model::find
    auto cursor = coll.find(model::find(doc_view).limit(10));

/////////////////////////////////////////////////////////////////////
/// aggregate
/////////////////////////////////////////////////////////////////////

    // create the pipeline
    pipeline p;
    p.match(doc_view);
    p.skip(10);

    // perform the aggregation
    model::aggregate aggregation(p);
    auto results = coll.aggregate(aggregation);

/////////////////////////////////////////////////////////////////////
/// count
/////////////////////////////////////////////////////////////////////

    // count everything
    auto count = coll.count();

    // count documents matching doc_view;
    auto count = coll.count(doc_view);

/////////////////////////////////////////////////////////////////////
/// distinct
/////////////////////////////////////////////////////////////////////

    // get distinct bson values for key "x"
    auto distinct_x = coll.distinct("x");

/////////////////////////////////////////////////////////////////////
/// delete
/////////////////////////////////////////////////////////////////////

    // delete one document matching view
    auto result = coll.delete_one(doc_view);

    // delete all documents matching view
    auto result = coll.delete_many(doc_view);

/////////////////////////////////////////////////////////////////////
/// insert
/////////////////////////////////////////////////////////////////////

    // insert a single document
    auto result = coll.insert_one(doc_view);
  
    // insert a bunch of documents
    model::insert_many docs { 
        std::initializer_list<bson::document::view>{ doc, doc, doc }
    };
    auto result = coll.insert_many(docs);

/////////////////////////////////////////////////////////////////////
/// replaceOne
/////////////////////////////////////////////////////////////////////

    auto result = coll.replace_one(model::replace_one{criteria, replacement});
 
/////////////////////////////////////////////////////////////////////
/// update
/////////////////////////////////////////////////////////////////////

    // update a single document matching criteria
    auto result = coll.update_one(model::update_one{criteria, update_doc});
    auto result = coll.update_many(model::update_one{criteria, update_doc});

/////////////////////////////////////////////////////////////////////
/// bulkWrite
/////////////////////////////////////////////////////////////////////

    // build up array of model::writes
    std::vector<model::write> writes;
    writes.push_back(model::insert_one{doc_view});
    writes.push_back(model::insert_one{doc_view});

    // bulk write
    model::bulk_write bwm{writes};
    bwm.ordered(false);
    auto result = coll.bulk_write(bwm);

/////////////////////////////////////////////////////////////////////
/// findOneAndDelete
/////////////////////////////////////////////////////////////////////

    auto doc = coll.find_one_and_delete(model::find_one_and_delete{criteria});

/////////////////////////////////////////////////////////////////////
/// findOneAndReplace
/////////////////////////////////////////////////////////////////////

    auto doc = coll.find_one_and_replace(model::find_one_and_replace{criteria, replacement});

///////////////////////////////////////////////////////////////////// 
/// findOneAndUpdate
/////////////////////////////////////////////////////////////////////

    auto doc = coll.find_one_and_update(model::find_one_and_update{criteria, update});

/////////////////////////////////////////////////////////////////////
/// explain
/////////////////////////////////////////////////////////////////////

    auto explanation = coll.explain(model::find{doc_view});